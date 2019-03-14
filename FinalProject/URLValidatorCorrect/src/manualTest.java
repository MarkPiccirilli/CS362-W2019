//manual test

import java.util.Scanner;

public class manualTest {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		System.out.println("Enter URL: ");
		String url = s.next();

		UrlValidator url_val = new UrlValidator();

		boolean a = url_val.isValid(url);

		System.out.println(a);
	}
}
