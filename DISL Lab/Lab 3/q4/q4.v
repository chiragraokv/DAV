module q4(F, A, B, C, D);
	input A, B, C, D;
	output F;
	nand n1(Dn, D, D);
	nand n2(o1, Dn, B);
	nand n3(o2, A, D);
	nand n4(o3, o1, o2);
	nand n5(F, o3, o3);
endmodule
