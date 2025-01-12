# Keywords
- `this` - current instance
- `type` - type of a type
- `tag` - defines a tag
- `mod` - defines a module
- `use` - imports a module
- `comp` - defines a compound type
- `sum` - defines a sum type
- `trait` - defines a trait
- `def` - defines a trait for a type
- `proc` - defines a procedure
- `var` - defines a variable
- `if` / `elif` / `else` - if statement
- `loop` - loop statement
- `while` -  while statement
- `for` - for statement
- `each` / `in` - each statement
- `match` - match statement
- `echo` - prints values
- `ret` - returns values
- `next` - continues the execution
- `jump` - jumps to a label
- `try` - used with errors
- `as` - casts to a type
# Operators
1.  - `a[]` - array access
    - `a()` - procedure call
    - `a.b` - member access
2.  - `-b` - negation
    - `!b` - not
3. Mixable, left to right
    - `*` - multiplication
    - `/` - division
    - `%` - modulo
    - `^` - power
4. Mixable, left to right
    - `+` - addition
    - `-` - subtraction
5. Not mixable, chaining
    - `&` - logical and
    - `|` - logical or
    - `<` - less than
    - `>` - greater than
    - `<=` - less than or equal
    - `>=` - greater than or equal
    - `==` - equal
    - `!=` - not equal
6. Mixable, right to left
    - `=` - assign
    - `+=` - add assign
    - `-=` - subtract assign
    - `*=` - multiply assign
    - `/=` - divide assing
    - `%=` - modulo assign
    - `^=` - power assign
# Expressions
- `Block` - Block of code
    - `darr<Expr>` body
- `Mod` - Module
    - `Path` path
    - `darr<Expr>` body
- `Use` - Use
    - `Path` path
- `Field` - Field
    - `Path` _type
    - `str` name
- `Comp` - Compound type
    - `Path` path
    - `darr<Expr>` fields
    - `darr<Expr>` body
- `Sum` - Sum type
    - `Path` path
    - `darr<Expr>` opts
    - `darr<Expr>` body
- `Trait` - Trait
    - `Path` path
    - `darr<Expr>` body
- `Def` - Define
    - `Path` path
    - `opt<Path>` target
    - `darr<Expr>` body
- `TagDef` - Tag definition
    - `Path` path
    - `darr<Expr>` args
    - `darr<Expr>` body
- `ProcDef` - Procedure definition
    - `opt<Path>` ret_type
    - `Path` path
    - `darr<Expr>` args
    - `darr<Expr>` body
- `VarDef` - Variable definition
    - `opt<Path>` _type
    - `Path` path
    - `opt<ptr<Expr>>` value
- `LocalVarDef` - Local variable definition
    - `opt<Path>` _type
    - `str` name
    - `opt<ptr<Expr>>` value
- `ProcCall` - Procedure call
    - `Path` path
    - `darr<Expr>` args
- `VarUse` - Variable use
    - `Path` path
- `StringLit` - String literal
    - `str` value
- `CharLit` - Character literal
    - `str` value
- `IntLit` - Integer literal
    - `str` value
- `FloatLit` - Floating literal
    - `str` value
- `BoolLit` - Boolean literal
    - `bool` value
# Types
- `isize`, `i8`, `i16`, `i32`, `i64`, `int` = `i32`
- `usize`, `u8`, `u16`, `u32`, `u64`, `uint` = `u32`
- `bool`
- `f32` ,`f64`, `float` = `f64`
- `c8`, `c16`, `c32`, `char` = `c32`
- `s8`, `s16`, `s32`, `str` = `s32`
# Basic tags
- `#cmp` - marks expression as compile time constant
- `#pub` - marks item as public
- `#inl` - marks "proc"/"var" to be inlined by the compiler
- `#uni` - unified "comp"
- `#exh` - exhaustive "match"
- `#del` - delay execution of a "local"
- `#self` - marks sub to act on a instance
- `#rest` - marks arg as a rest arg
- `#os(str os_name)`
- `#bind(str sub_name)`
- `#req(str header)`