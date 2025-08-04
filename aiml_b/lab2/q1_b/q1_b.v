module q1(a, b, c, d, f);
    input a, b, c, d;
    output f;
    assign f = (((~a)&(~b)&d)|(b&(~c)&(~d))|a&(~b)&d|(a&(~b)&c));
    
endmodule
