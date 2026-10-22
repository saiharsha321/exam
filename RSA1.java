import java.math.BigInteger;
import java.util.Random;
import java.util.Scanner;

public class RSA1{
    static BigInteger generateE(BigInteger phi) {
        Random r = new Random();
        BigInteger e;
        do {
            e = BigInteger.valueOf(2 + r.nextInt(phi.intValue() - 2));
        } while (!e.gcd(phi).equals(BigInteger.ONE));
        return e;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a Prime number: ");
        BigInteger p = sc.nextBigInteger();

        System.out.print("Enter another prime number: ");
        BigInteger q = sc.nextBigInteger();

        BigInteger n = p.multiply(q);
        BigInteger phi = p.subtract(BigInteger.ONE)
                          .multiply(q.subtract(BigInteger.ONE));

        BigInteger e = generateE(phi);
        BigInteger d = e.modInverse(phi);

        System.out.println("Encryption keys are: " + e + ", " + n);
        System.out.println("Decryption keys are: " + d + ", " + n);

        sc.close();
    }
}