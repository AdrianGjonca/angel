String test = "abc";

//Equivalent
test = tocap(replace(test, "a", "c"));

//Test 1
test = test@replace("a","c")@tocap();

//Test 2
test = test @ 
       replace("a","c") @
       tocap();

//Test 3
test =	test			@
	replace("a", "c")	@
	tocap()			;
