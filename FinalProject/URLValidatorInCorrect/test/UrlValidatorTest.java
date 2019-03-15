

import junit.framework.TestCase;
import java.util.Random;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not! 





public class UrlValidatorTest extends TestCase {


	public UrlValidatorTest(String testName) {
		super(testName);
	}

   
   
	public void testUnitTest()
	{
		System.out.println("\n\nUnit Tests:\n");
		
		//default Constructor validator used throughout testing
		UrlValidator url_validator_default = new UrlValidator();
		//unit url testing with default constructor
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
				"http://",
				"www.google.com",
				"ebay.com"
				};
		for(int i=0; i<URLFalse.length; i++) {
			try {
				assertFalse(url_validator_default.isValid(URLFalse[i]));
				System.out.format("PASSED URL Test %d\n", i + 1 + URLTrue.length);
			} catch (AssertionError a){
				System.out.format("FAILED URL Test %d\n", i + 1 + URLTrue.length);
			}
		}
		
		//unit scheme testing with default constructor
		//should return true
		String SchemeTrue[] = {"ftp", "http", "https", "HTTP"};
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
		
		//unit scheme testing with scheme overload constructor
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
		
		//unit authority testing with default constructor
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
		
		//unit path testing with default constructor
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
				String PathFalse2Slashes[] = {"//..", "/../test123/.//file"};
				for(int i=0; i<PathFalse2Slashes.length; i++) {
					try {
						assertFalse(url_val_2slashes.isValidPath(PathFalse2Slashes[i]));
						System.out.format("PASSED path allow 2 slashes test %d\n", i + 1 + PathTrue2Slashes.length);
					} catch(AssertionError a) {
						System.out.format("FAILED path allow 2 slashes test %d\n", i + 1 + PathTrue2Slashes.length);
					}
				}
		
		//unit query testing with default constructor
		String QueryTrue[] = {"", "?action=edit", "?action=view&mode=down"};
		for(int i=0; i<QueryTrue.length; i++) {
			try {
				assertTrue(url_validator_default.isValidQuery(QueryTrue[i]));
				System.out.format("PASSED query test %d\n", i + 1);
			} catch(AssertionError a) {
				System.out.format("FAILED query test %d\n", i + 1);
			}
		}
		//unit fragment testing
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
   
	public void testRandomTest()
   	{
	   	int numberOfTests = 20;
	   	System.out.println("\n\nRandom Tests:\n");
	   	for(int i=0; i<numberOfTests; i++) {
		   	RandomTest();
	   	}
	   
   	}
	
	public void RandomTest()
	{
		//create random object
		Random rand = new Random();
		
		//select random scheme
		String testSchemes[] = {"http", "https", "ftp", "", "HTTP", "FTP"};
		String scheme = testSchemes[rand.nextInt(testSchemes.length)];
		
		//select schemes for constructor
		String schemes[] = {"http", "https", "ftp", ""};
		boolean arr[] = new boolean[schemes.length];
		int count = 0;
		for(int i=0; i<schemes.length; i++) {
			arr[i] = rand.nextBoolean();
			if(arr[i] == true) {
				count++;
			}
		}
		String constructor_schemes[] = new String[count];
		int c = 0;
		for(int i = 0; i < arr.length; i++) {
			if(arr[i] == true) {
				constructor_schemes[c] = schemes[i];
				c++;
			}
		}
		//select random authority
		String authorities[] = {"ebay.com", "www.google.com", "www.gmail.com", "leo.com", "localhost"};
		String authority = authorities[rand.nextInt(authorities.length)]; 
		
		//select random path
		String paths[] = {"/test", "/test123", "", "/test/hello", "//test"};
		String path = paths[rand.nextInt(paths.length)];
		//select random select random query
		String queries[] = {"?", "?action=edit", "?action=view&mode=down"};
		String query = queries[rand.nextInt(queries.length)];
		
		//concatonate strings to build url
		String url;
		if(scheme == "") {
			url = authority + path + query;
		}
		else {
			url = scheme + "://" + authority + path + query;
		}
		//select random options
		boolean allow2Slashes = rand.nextBoolean();
		boolean allowAllSchemes = rand.nextBoolean();
		boolean allowLocalUrls = rand.nextBoolean();
		boolean noFragments = rand.nextBoolean();
		long options = 0;
		if(allow2Slashes) {
			options = options + UrlValidator.ALLOW_2_SLASHES;
		}
		if(allowAllSchemes) {
			options = options + UrlValidator.ALLOW_ALL_SCHEMES;
		}
		if(allowLocalUrls) {
			options = options + UrlValidator.ALLOW_LOCAL_URLS;
		}
		if(noFragments) {
			options = options + UrlValidator.NO_FRAGMENTS;
		}
		
		//run constructor
		UrlValidator url_randomValidator;
		if(options == 0 & constructor_schemes.length == 0) {
			url_randomValidator = new UrlValidator();
		}
		else if(options == 0) {
			url_randomValidator = new UrlValidator(constructor_schemes);
		}
		else if(constructor_schemes.length == 0) {
			url_randomValidator = new UrlValidator(options);
		}
		else {
			url_randomValidator = new UrlValidator(constructor_schemes, options);
		}
		
		//test url with isValid method of randomly generated constructor
		try {
			assertTrue(url_randomValidator.isValid(url));
			System.out.format("TRUE: %s\n", url);
		} catch(AssertionError | ExceptionInInitializerError | NoClassDefFoundError a) {
			System.out.format("FALSE: %s\n", url);
		}
		if(constructor_schemes.length > 0) {
			System.out.format("Constructor information:  schemes: ");
			for(int i = 0; i < constructor_schemes.length - 1; i++) {
				System.out.format("%s, ", constructor_schemes[i]);
			}
			System.out.format("%s.  ", constructor_schemes[constructor_schemes.length - 1]);
		}
		else {
			System.out.format("Constructor information: options: ");
			}
		if(allow2Slashes) {
			System.out.format("allow 2 slashes ");
		}
		if(allowAllSchemes) {
			System.out.format("allow all schemes ");
		}
		if(allowLocalUrls) {
			System.out.format("allowLocalUrls ");
		}
		if(noFragments) {
			System.out.format("no fragments ");
		}
		System.out.println();
		System.out.println();
	}
}
