```````````````````````````````````````````````` use
` use foo:bar;
```````````````````````````````````````````````` mod
` mod foo:bar;
```````````````````````````````````````````````` comp, field
` comp SomeComp (
`     i32 foo,
`     i32 bar,
` ) {};
```````````````````````````````````````````````` enum, option
` enum SomeEnum (
`     i32 foo,
`     i32 bar,
`     
`     Option0,
`     Option1(i32 foo, f32 bar),
`     Option2(),
` ) {};
```````````````````````````````````````````````` tag_def, arg
` tag test_tag(string foo, int bar) { };
```````````````````````````````````````````````` prop
` prop SomeProp { };
```````````````````````````````````````````````` def
` def SomeProp<T, TT>, SomeObject<T, TT> { };
```````````````````````````````````````````````` sub_def, arg
` foo:bar xyz() {};
` sub foo(i32 bar) {
`     foo:bar xyz = 1;
`     var bar = 1;
`     if 0 { } elif 1 { } else { };
`     loop { };
`     while 2 { };
`     for i, i < 1, i += 1 { };
`     each i in foo { };
`     match foo { 0 { }, 1 { }, };
`     ret ~foo 1;
`     next ~foo;
`     jump ~foo;
`     try ~foo bar();
` };
```````````````````````````````````````````````` var_def
` foo:bar xyz = 1;
` var bar = 1;
````````````````````````````````````````````````

` analyzer
    ` check if label defined
    ` check if enum_inst arg number is right
    ` check if comp_inst fields exist
    ` check types
        ` when assigning check if type matches
        ` when giving to sub_call check
        ` when giving to comp_inst
        ` when giving to enum_inst
        ` when ops
    ` apply type
        ` var_def
        ` local_var_def
` op overloading
` combo ops
` combo var_defs
` prop
` def
` each
` local variable shadowing

` fix leaks

#req("stdint.h")
int main(vec<int> bar) {
    vec<f32> foo = vec<f32>:new_with_cap(2);
    foo.push('1');
    foo.push('2');
    foo.push('3');

    foo[1];

    SomeEnum bar1 = SomeEnum:Opt1;
    SomeEnum bar2 = SomeEnum:Opt2(1);
    SomeEnum bar3 = SomeEnum:Opt3(1, 2);

    match bar1 {
        SomeEnum:Opt1,
        _ {},
        SomeEnum:Opt1,
        SomeEnum:Opt3(a, b) {
            a + b;
        },
        SomeEnum:Opt1 {},
        SomeEnum:Opt2(a) {
            a + a;
        },
    };
};

int abc;

enum SomeEnum (
    Opt1(),
    Opt2(int a),
    Opt3(int a, int b),
);

#gen("T")
comp vec<T> (
    ptr<T> buf,
    int len,
    int cap,
);

#gen("T")
def vec<T> {
    vec<T> new_with_cap(int cap) {
        ret new vec<T> {
            buf = mem:alloc(mem:size<T>() * cap),
            len = 0,
            cap = cap,
        };
    };

    #self
    ptr<T> array_get(int index) {
        ret this.buf + index;
    };

    #self
    sub push(T item) {
        (this.buf + this.len)@ = item;
        this.len += 1;

        if this.len == this.cap {
            this.cap *= 2;
            this.buf = mem:realloc(this.buf, mem:size<T>() * this.cap);
        };
    };
};

#req("stdlib.h")
mod mem {
    #bind("malloc")
    sub alloc();

    #bind("realloc")
    sub realloc();

    #bind("sizeof")
    sub size();
};

#gen("T")
comp ptr<T> ();