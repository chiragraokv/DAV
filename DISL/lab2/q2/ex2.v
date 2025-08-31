module ex2(a,b,c,d,f,g);
input a,b,c,d;
output f,g;
assign f = (a&b)|((~(a&b))&(c&d))|(a&b&c&d);
assign g = (b&c&d)|(~b&~c&d)|(~b&c&~d)|(b&~c&~d);
endmodule
