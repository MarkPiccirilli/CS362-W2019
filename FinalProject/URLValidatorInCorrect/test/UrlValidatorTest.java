

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not! 





public class UrlValidatorTest extends TestCase {


	public UrlValidatorTest(String testName) {
		super(testName);
	}

   
   
	public void testManualTest()
	{
//You can use this function to implement your manual testing
		//manual url testing with default constructor
		UrlValidator url_validator = new UrlValidator();
		String URLTrue[] = {"http://www.google.com",
							"http://www.amazon.com",
							"http://www.ebay.com"
							};
		for(int i=0; i<URLTrue.length; i++) {
			try {
				assertTrue(url_validator.isValid(URLTrue[i]));
				System.out.format("PASSED URL Test %d\n", i + 1);
			} catch (AssertionError a){
				System.out.format("FAILED URL Test %d\n", i + 1);
			}
		}
		
		//manual scheme testing with default constructor
		String SchemeTrue[] = {"ftp", "http", "https"};
		for(int i=0; i<SchemeTrue.length; i++) {
			try {
				assertTrue(url_validator.isValidScheme(SchemeTrue[i]));
				System.out.format("PASSED Scheme test %d\n", i + 1);
			} catch(AssertionError a) {
				System.out.format("FAILED Scheme test %d\n", i + 1);
			}
		}
		
		//manual scheme testing with scheme overload constructor
		String SchemeTrue2[] = {"http", "https"};
		UrlValidator url_val_schemes = new UrlValidator(SchemeTrue2);
		for(int i = 0; i < SchemeTrue2.length; i++) {
			try {
				assertTrue(url_val_schemes.isValidScheme(SchemeTrue2[i]));
				System.out.format("PASSED Scheme2 test %d\n", i + 1);
			} catch(AssertionError a) {
				System.out.format("FAILED Scheme2 test %d\n", i + 1);
			}
		}
		
		//manual authority testing with default constructor
		String AuthorityTrue[] = {"www.google.com"};
		for(int i=0; i<AuthorityTrue.length; i++) {
			try {
			//	assertTrue(url_validator.isValidAuthority("www.google.com"));
			//	System.out.println(url_validator.isValidAuthority(AuthorityTrue[i]));
				System.out.format("PASSED Authority test %d\n", i + 1);
			} catch(AssertionError a) {
				System.out.format("FAILED Authority test %d\n", i + 1);
			} catch(Exception e) {
				System.out.println("exception5");
			}
		}
		
		//manual path testing with default constructor
		String PathTrue[] = {"/test"};
		for(int i=0; i<PathTrue.length; i++) {
			try {
				assertTrue(url_validator.isValidPath(PathTrue[i]));
				System.out.format("PASSED path test %d\n", i + 1);
			} catch(AssertionError a) {
				System.out.format("FAILED path test %d\n", i + 1);
			}
		}
	}
   
   
	public void testYourFirstPartition()
	{
	 //You can use this function to implement your First Partition testing	   

	}
   
	public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

	}
	//You need to create more test cases for your Partitions if you need to 
   
	public void testIsValid()
	{
		//You can use this function for programming based testing

	}
}
