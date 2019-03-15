//manual test

import java.util.Scanner;

public class manualTest {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		while(true) {
			System.out.println("Enter URL or type quit: ");
			String url = s.next();
			if(url.equals("quit")) {
				System.out.println("test");
				break;
			}

			UrlValidator url_val = new UrlValidator();

			boolean a = url_val.isValid(url);

			System.out.println(a);
		}
	}
}
