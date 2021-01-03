// C Parser heavily based on:
//
//  Parsing Expression Grammar of C for Mouse 1.1 - 1.5.
//  Based on standard ISO/IEC 9899.1999:TC2, without preprocessor.
//  Requires semantics class to process Typedefs.
//
//---------------------------------------------------------------------------
//
//  Copyright (C) 2007, 2009, 2010 by Roman R Redziejowski (www.romanredz.se).
//
//  The author gives unlimited permission to copy and distribute
//  this file, with or without modifications, as long as this notice
//  is preserved, and any changes are properly documented.
//
//  This file is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//


Script = statements:BlockStatement* _? {
    return new Block(statements, location());
}

BlockStatement = _? statement:(Define / Include / Mode / Message / For / While / If / Switch / DefineFunc / PredefineFunc / ClosedStatement) {
    return statement;
};

ClosedStatement = _? statement:Statement _? ";" {
    return statement;
}

Statement = (
  Return /
  Enum /
  Struct /
  TypedefStruct /
  DefineArray /
  DefineVar /
  Expr
);

Message = "message" _ name:(Id / "*") _? block:Block {
  return new Message(name, block, location());
}
Mode = "mode" _ name:Id _? block:Block {
  return new Mode(name, block, location());
}

Enum = "enum" _ name:Id _? "{" _? first:SimpleAssign rest:(_? "," _? SimpleAssign)* _? ","? _? "}" {
    return new Enum(name, [first, ...rest.map(r => r[3])], location());
}

StructDef = "{" _? first:DefineVar _? ";" rest:(_? DefineVar _? ";")* _? "}" {
  return [first, ...rest.map(r => r[1])];
}

TypedefStruct = "typedef" _ "struct" _? def:StructDef _? name:Id {
    return new Struct(name, def, location());
}
Struct = "struct" _ name:Id _? def:StructDef {
    return new Struct(name, def, location());
}

ProgMem = _? "PROGMEM"

DefineArray = ("const" _)? type:Type _? id:Id "[" _? size:Expr? _? "]"
              ProgMem?
              values:(_? "=" _? StructValuesExpr)? {
    return new DefineArray(
      type,
      id,
      size ?? null,
      values ? values[3].values : null,
      location()
    );
}

DefineVar = constant:("const" _)? type:Type _? id:Id ProgMem? assign:(_? "=" _? (Expr / StructValuesExpr))? {
    return new DefineVar(!!constant, type, id, assign ? assign[3] : null, location());
}

PredefineFunc = returnType:Type _? name:Id _? "(" _? args:(ArgList/NoArgs) _? ")" _? ";" {
    return new DefineFunc(name, args, returnType, null, location());
}

DefineFunc = returnType:Type _? name:Id _? "(" _? args:(ArgList/NoArgs) _? ")" _? block:Block {
    return new DefineFunc(name, args, returnType, block, location());
}

Return = "return" expr:(_ Expr)? {
    return new Return(expr ? expr[1] : null, location());
}

NoArgs = "void" / "" {
    return [];
}
ArgList = first:Arg rest:(_? "," _? Arg)* {
  return [first, ...rest.map(item => item[3])];
}

Arg = type:Type _? star:"*"? id:Id defaultExpr:(_? "=" _? expr:Expr)? {
    return new Arg(type + (star ?? ''), id, defaultExpr ? defaultExpr[3] : null, location());
}

Type = (
  ("const" _)?
  (
    "char" /
    "void" / 
    "u"? "int" ("8" / "16") "_t" /
    "float" /
    ("unsigned" _)? ("int" / "long") /
    Id
  )
  ![a-zA-Z0-9]
  (_? "*")*
) {
    return text();
};

Define = "#define" _ id:Id _ expr:Expr [\n] {
    return new Define(id, expr, location());
}

Include = "#include" _ path:String [\n] {
    return new Include(path, location());
}

For = "for" _? "(" _? initial:Statement? _? ";" _? test:Expr? _? ";" _? step:Statement? _? ")" _? block:Block {
    return new For(initial, test, step, block, location());
};

While = "while" _? "(" _? test:Expr _? ")" _? block:Block {
    return new For(null, test, null, block, location());
};

If = "if" _? "(" _? test:Expr _? ")" _? block:Block otherwise:(_? "else" _ ElseStatement)? {
    return new If(test, block, otherwise ? otherwise[3] : null, location());
};

ElseStatement = If / Block;

Switch = "switch" _? "(" _? expr:Expr _? ")" _? "{" cases:SwitchCase+ _? "}" {
    return new Switch(expr, cases, location());
};

SwitchCase = _? "case" _ expr:Expr _? ":" statements:BlockStatement* {
    return new SwitchCase(expr, statements, location());
}

PrimaryExpr = Variable / Literal / SubExpr;

// {@todo} / "(" TypeName ")" "{" InitializerList ","? "}"
// {@todo}: mulitple accessors
PostfixExpr = expr:PrimaryExpr post:PostfixOperator* {
    let rv = expr;
    post.forEach(cb => {
        rv = cb(rv);
    });
    return rv;
}

PostfixOperator = PostIncr / ObjAccessor / ArrAccessor / CallExpr

PostIncr = _? op:("++" / "--") {
  return expr => new UnaryOp(expr, ('X' + op) as ("X++" | "X--"), location());
}

ObjAccessor = _? ("." / "->") _? id:Id {
  return obj => new ObjectAccessor(obj, id, location());
}
  
ArrAccessor = _? "[" _? expr:Expr _? "]" {
  return obj => new ArrayAccessor(obj, expr, location());
}
  
CallExpr = _? "(" _? args:ExprList? _? ")" {
  return obj => new Call(obj, args ?? [], location());
}


UnaryExpr
  = PostfixExpr
  / PreIncr
  / PreUnary
//  {@todo} "sizeof" (UnaryExpr / "(" TypeName ")" )

PreIncr = op:("++" / "--") _? expr:UnaryExpr {
  return new UnaryOp(expr, (op + 'X') as ("++X" | "--X"), location());
}

PreUnary = op:("&" / "*" / "+" / "-" / "~" / "!") expr:CastExpr {
  return new UnaryOp(expr, op, location());
}

CastExpr = Cast / UnaryExpr
Cast = "(" _? type:Type _? ")" _? expr:CastExpr {
  return new Cast(type, expr, location());
}

MultiplicativeExpr = first:CastExpr rest:(_? ("*" / "/" / "%") _? CastExpr)* {
  let rv = first;
  rest.forEach(parts => {
    rv = new BoolOp(rv, parts[1], parts[3], location());
  });
  return rv;
}

AdditiveExpr = first:MultiplicativeExpr rest:(_? ("+" / "-") _? MultiplicativeExpr)* {
  let rv = first;
  rest.forEach(parts => {
    rv = new BoolOp(rv, parts[1], parts[3], location());
  });
  return rv;
}

ShiftExpr = first:AdditiveExpr rest:(_? ("<<" / ">>") _? AdditiveExpr)* {
  let rv = first;
  rest.forEach(parts => {
    rv = new BoolOp(rv, parts[1], parts[3], location());
  });
  return rv;
}

RelationalExpr = first:ShiftExpr rest:(_? ("<=" / ">=" / "<" / ">") _? ShiftExpr)* {
  let rv = first;
  rest.forEach(parts => {
    rv = new BoolOp(rv, parts[1], parts[3], location());
  });
  return rv;
}

EqualityExpr = first:RelationalExpr rest:(_? ("==" / "!=") _? RelationalExpr)* {
  let rv = first;
  rest.forEach(parts => {
      rv = new BoolOp(rv, parts[1], parts[3], location());
  });
  return rv;
}

BinAndExpr = first:EqualityExpr rest:(_? "&" _? EqualityExpr)* {
  let rv = first;
  rest.forEach(parts => {
    rv = new BoolOp(rv, parts[1], parts[3], location());
  });
  return rv;
}

ExclOrExpr = first:BinAndExpr rest:(_? "^" _? BinAndExpr)* {
  let rv = first;
  rest.forEach(parts => {
    rv = new BoolOp(rv, parts[1], parts[3], location());
  });
  return rv;
}

InclOrExpr = first:ExclOrExpr rest:(_? "|" _? ExclOrExpr)* {
  let rv = first;
  rest.forEach(parts => {
    rv = new BoolOp(rv, parts[1], parts[3], location());
  });
  return rv;
}

LogicAndExpr = first:InclOrExpr rest:(_? "&&" _? InclOrExpr)*{
  let rv = first;
  rest.forEach(parts => {
    rv = new BoolOp(rv, parts[1], parts[3], location());
  });
  return rv;
}

LogicOrExpr = first:LogicAndExpr rest:(_? "||" _? LogicAndExpr)* {
  let rv = first;
  rest.forEach(parts => {
    rv = new BoolOp(rv, parts[1], parts[3], location());
  });
  return rv;
}

ConditionalExpr = first:LogicOrExpr rest:(_? "?" _? Expr _? ":" _? LogicOrExpr)* {
  let rv = first;
  rest.forEach(parts => {
    rv = new ConditionalOp(rv, parts[3], parts[7], location());
  });
  return rv;
}


SimpleAssign = v:Variable _? "=" _? expr:Expr {
    return new Assign(v, expr, location());
};

Variable = id:Id {
    return new Variable(id, location());
}

Assigment = left:UnaryExpr _? op:(
    "=" / "*=" / "/=" / "%=" / "+=" / "-=" / "<<=" / ">>=" / "&=" / "^=" / "|="
) _? right:AssignmentExpr {
  return new BoolOp(left, op, right, location());
}
AssignmentExpr = Assigment / ConditionalExpr;

// {@todo}
TypeName = Id

Expr = AssignmentExpr

ExprList = first:Expr rest:(_? "," _? Expr)* {
  return [first, ...rest.map(item => item[3])];
}

StructValuesExpr = "{" _? values:DefExprList _? "}" {
  return new StructValues(values, location());
}
DefExpr = StructValuesExpr / CastExpr
DefExprList = first:DefExpr rest:(_? "," _? DefExpr)* {
  return [first, ...rest.map(item => item[3])];
}

SubExpr = "(" _? expr: Expr _? ")" {
    return expr;
}


Block = "{" statements:BlockStatement* _? "}" {
    return new Block(statements, location());
}


Id = [A-Za-z0-9_]+ {
  return text();
}

Literal = value:(Number / Char / Strings / True / False / Null) {
  return new Constant(value, location());
}

Char = "'" char:StringChar "'" {
  const code = char.charCodeAt(0);
  if (code > 255) {
    throw new Error('Only ascii characters are intepreted');
  }
  return code;
}

String = '"' chars:StringChar* '"' { return chars.join(""); }

Strings = first:String rest:(_? String)* {
  return first + rest.map(r => r[1]).join('');
}

StringChar = StringCharUnescaped / StringEscapedChar;
StringEscapedChar
  = "\\"
    sequence:(
        '"'
      / "'"
      / "\\"
      / "/"
      / "b" { return "\b"; }
      / "f" { return "\f"; }
      / "n" { return "\n"; }
      / "r" { return "\r"; }
      / "t" { return "\t"; }
      / "x" digits:$(HexDigit HexDigit) {
          return String.fromCharCode(parseInt(digits, 16));
        }
    )
{
  return sequence;
}
StringCharUnescaped = [^\0-\x1F\x22\x5C]
HexDigit = [0-9a-f]i

Null "null" = "null" {
  return null;
}

True "true" = "true" {
  return true;
}

False "false" = "false" {
  return false;
}

HexNumber = "0x" HexDigit+ {
  return parseInt(text().substring(2), 16);
}

Number "number" = HexNumber / Float / Int

Int = Zero / [-+]?[1-9][0-9]* {
  return parseInt(text(), 10);
}

Zero = "0" {
  return 0;
}

Float = [-]?([0-9]+)? "." [0-9]+ {
  return parseFloat(text());
}

_ "whitespace" = (Whitespace / Comment)+ {
  return text();
}

Whitespace = [ \t\n\r]
Comment = LineComment / LongComment
LineComment = "//" ([^\n])* [\n]
LongComment = "/*" (!"*/" .)* "*/"
