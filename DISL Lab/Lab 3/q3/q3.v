module q3(F, A, B, C, D);
	input A, B, C, D;
	output F;
	nor n1(Dn, D, D);
	nor n2(o1, C, Dn);
	nor n3(o2, A, Dn);
	nor n4(o3, o1, o2);
	nor n5(F, o3, o3);
endmodule
