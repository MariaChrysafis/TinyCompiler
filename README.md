# Tiny Compiler

Generates abstract syntax tree for a custom, simple language.

```
let $y = 10
let $z = 5
let $x = $y + 10 + $z
let $x = $y + 5
print $x
if $x > 10 {
    let $x = $y
    let $w = 54
    print $w
    if $w < 30 {
        let $u = 10 * 10
        print $u
    }
}
```

Currently supports
- if statements (`>`, `<`)
- assignments (e.g. `$x = 10`)
- expressions (`+`, `-`, `/`, `*`)
- print statements (e.g. `print $x`)