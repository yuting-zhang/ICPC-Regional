import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String line = sc.nextLine();
		BigInteger fact = new BigInteger(line);
		BigInteger answer = BigInteger.ONE;
		
		while (fact != BigInteger.ONE) {
			fact = fact.divide(answer);
			answer.add(BigInteger.ONE);
		}
		System.out.println(answer);
	}
}
