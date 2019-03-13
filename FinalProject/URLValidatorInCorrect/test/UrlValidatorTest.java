

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
		//default Constructor validator used throughout testing
		UrlValidator url_validator_default = new UrlValidator();
		//manual url testing with default constructor
		//should return true
		String URLTrue[] = {"http://www.google.com",
							"http://www.amazon.com",
							"http://www.ebay.com"
							};
		for(int i=0; i<URLTrue.length; i++) {
			try {
				assertTrue(url_validator_default.isValid(URLTrue[i]));
				System.out.format("PASSED URL Test %d\n", i + 1);
			} catch (AssertionError a){
				System.out.format("FAILED URL Test %d\n", i + 1);
			}
		}
		//should return false
		String URLFalse[] = {"djgljaldkf",
				"zon.com",
				"http://"
				};
		for(int i=0; i<URLFalse.length; i++) {
			try {
				assertFalse(url_validator_default.isValid(URLFalse[i]));
				System.out.format("PASSED URL Test %d\n", i + 1 + URLTrue.length);
			} catch (AssertionError a){
				System.out.format("FAILED URL Test %d\n", i + 1 + URLTrue.length);
			}
		}
		
		//manual scheme testing with default constructor
		//should return true
		String SchemeTrue[] = {"ftp", "http", "https"};
		for(int i=0; i<SchemeTrue.length; i++) {
			try {
				assertTrue(url_validator_default.isValidScheme(SchemeTrue[i]));
				System.out.format("PASSED Scheme test %d\n", i + 1);
			} catch(AssertionError a) {
				System.out.format("FAILED Scheme test %d\n", i + 1);
			}
		}
		//should return false
		String SchemeFalse[] = {"telnet", "", "dlkfjsl"};
		for(int i=0; i<SchemeFalse.length; i++) {
			try {
				assertFalse(url_validator_default.isValidScheme(SchemeFalse[i]));
				System.out.format("PASSED Scheme test %d\n", i + 1 + SchemeTrue.length);
			} catch(AssertionError a) {
				System.out.format("FAILED Scheme test %d\n", i + 1 + SchemeTrue.length);
			}
		}
		
		//manual scheme testing with scheme overload constructor
		//should return true
		String SchemeTrue2[] = {"http", "https"};
		//constructor used for this test and next test
		UrlValidator url_val_schemes = new UrlValidator(SchemeTrue2);
		for(int i = 0; i < SchemeTrue2.length; i++) {
			try {
				assertTrue(url_val_schemes.isValidScheme(SchemeTrue2[i]));
				System.out.format("PASSED Scheme2 test %d\n", i + 1);
			} catch(AssertionError a) {
				System.out.format("FAILED Scheme2 test %d\n", i + 1);
			}
		}
		//should return false
		String SchemeFalse2[] = {"ftp", ""};
		for(int i = 0; i < SchemeFalse2.length; i++) {
			try {
				assertFalse(url_val_schemes.isValidScheme(SchemeFalse2[i]));
				System.out.format("PASSED Scheme2 test %d\n", i + 1 + SchemeTrue2.length);
			} catch(AssertionError a) {
				System.out.format("FAILED Scheme2 test %d\n", i + 1 + SchemeTrue2.length);
			}
		}
		
		//manual authority testing with default constructor
		//should return true
		String AuthorityTrue[] = {"www.google.com", "www.mark.com"};
		for(int i=0; i<AuthorityTrue.length; i++) {
			try {
				assertTrue(url_validator_default.isValidAuthority(AuthorityTrue[i]));
				System.out.format("PASSED Authority test %d\n", i + 1);
			} catch(AssertionError | ExceptionInInitializerError | NoClassDefFoundError a) {
				System.out.format("FAILED Authority test %d\n", i + 1);
			}
		}	
		//should return false
		String AuthorityFalse[] = {"*****", "###"};
		for(int i=0; i<AuthorityFalse.length; i++) {
			try {
				assertFalse(url_validator_default.isValidAuthority(AuthorityFalse[i]));
				System.out.format("PASSED Authority test %d\n", i + 1 + AuthorityTrue.length);
			} catch(AssertionError | ExceptionInInitializerError | NoClassDefFoundError a) {
				System.out.format("FAILED Authority test %d\n", i + 1 + AuthorityTrue.length);
			}
		}
		
		//manual path testing with default constructor
		//should return true
		String PathTrue[] = {"/test", "/test123", "", "/test/hello"};
		for(int i=0; i<PathTrue.length; i++) {
			try {
				assertTrue(url_validator_default.isValidPath(PathTrue[i]));
				System.out.format("PASSED path test %d\n", i + 1);
			} catch(AssertionError a) {
				System.out.format("FAILED path test %d\n", i + 1);
			}
		}
		//should return false
		String PathFalse[] = {"/..", "/test123//file"};
		for(int i=0; i<PathFalse.length; i++) {
			try {
				assertFalse(url_validator_default.isValidPath(PathFalse[i]));
				System.out.format("PASSED path test %d\n", i + 1 + PathTrue.length);
			} catch(AssertionError a) {
				System.out.format("FAILED path test %d\n", i + 1 + PathTrue.length);
			}
		}
		//allow to slashes constructor for next path tests
		UrlValidator url_val_2slashes = new UrlValidator(UrlValidator.ALLOW_2_SLASHES);
		//should return true
				String PathTrue2Slashes[] = {"/test", "//test123", "", "/test//hello"};
				for(int i=0; i<PathTrue2Slashes.length; i++) {
					try {
						assertTrue(url_val_2slashes.isValidPath(PathTrue2Slashes[i]));
						System.out.format("PASSED path allow 2 slashes test %d\n", i + 1);
					} catch(AssertionError a) {
						System.out.format("FAILED path allow 2 slashes test %d\n", i + 1);
					}
				}
				//should return false
				String PathFalse2Slashes[] = {"//..", "/test123///file"};
				for(int i=0; i<PathFalse2Slashes.length; i++) {
					try {
						assertFalse(url_val_2slashes.isValidPath(PathFalse2Slashes[i]));
						System.out.format("PASSED path allow 2 slashes test %d\n", i + 1 + PathTrue2Slashes.length);
					} catch(AssertionError a) {
						System.out.format("FAILED path allow 2 slashes test %d\n", i + 1 + PathTrue2Slashes.length);
					}
				}
		
		//manual query testing with default constructor
		String QueryTrue[] = {"", "?action=edit", "?action=view&mode=down"};
		for(int i=0; i<QueryTrue.length; i++) {
			try {
				assertTrue(url_validator_default.isValidQuery(QueryTrue[i]));
				System.out.format("PASSED query test %d\n", i + 1);
			} catch(AssertionError a) {
				System.out.format("FAILED query test %d\n", i + 1);
			}
		}
		//manual fragment testing
		//all fragments should be allowed for default constructor
		String FragmentTrue[] = {"", "kdajfsilj", "1234"};
		for(int i=0; i < FragmentTrue.length; i++) {
			try {
				assertTrue(url_validator_default.isValidFragment(FragmentTrue[i]));
				System.out.format("PASSED fragment test %d\n", i + 1);
			}catch(AssertionError a) {
				System.out.format("FAILED fragment test %d\n", i + 1);
			}
		}
		//constructor for next fragment test
		UrlValidator url_val_nofragments = new UrlValidator(UrlValidator.NO_FRAGMENTS);
		String FragmentFalse[] = {"dklfs", "hello", "1234", ""};
		for(int i = 0; i < FragmentFalse.length; i++) {
			try {
				assertFalse(url_val_nofragments.isValidFragment(FragmentFalse[i]));
				System.out.format("PASSED fragment test with no fragments constructor %d\n", i+1);
			} catch(AssertionError a) {
				System.out.format("FAILED fragment test with no fragments constructor %d\n", i+1);
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
