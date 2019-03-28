`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/03/26 21:55:19
// Design Name: 
// Module Name: sort_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module sort_tb();
reg [3:0] a, b, c, d;
wire [3:0] ra, rb, rc, rd;
sort4 dut(ra,rb,rc,rd,a,b,c,d);
initial
begin
a = 4'b0000; b = 4'b0000; c = 4'b0000; d = 4'b0000;
#20 a = 4'b1010; b = 4'b1110; c = 4'b0110; d = 4'b0011;
#20 a = 4'b1000;
#20 a = 4'b0111;
#20 b = 4'b0001;
#20 c = 4'b1111;
#20 d = 4'b1101;
end
endmodule
