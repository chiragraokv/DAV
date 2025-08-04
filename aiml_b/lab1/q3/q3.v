module q3(a,b,c,d,f,g);
input a,b,c,d;
output f,g;
assign f = (a&~c)|(b&c)|(~b&~c);
assign g = (a|~b|c)&(a+b+~c)&(~a|b|~c);
endmodule
