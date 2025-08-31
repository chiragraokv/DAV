module q1(F, A, B, C, D);
	input A, B, C, D;
	output F;
	nand n1(Dn, D, D);
	nand n2(Bn, B, B);
	nand n3(o1, C, Dn);
	nand n4(o2, A, Bn);
	nand n5(o3, o1, o2);
	nand n6(F, o3, o3);
endmodule
