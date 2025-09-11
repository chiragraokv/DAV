'include "fourto1.v"
module test;
reg [3:0] w;
reg [2:0] s;

fourto1 uut(
    .w(w),
    .s(s),
    .y(y)
)

initial begin 
w = 4'b0000; s=3'b0000;
end
endmodule