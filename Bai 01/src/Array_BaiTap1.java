
import java.util.Scanner;

public class Array_BaiTap1 {

    // psvm => ctrl + space
    public static void main(String[] args) {
        // auto format code: alt + shift + f
        System.out.println("On tap ve mang");
        // Khai bao mang
        int n = 10;
        int[] a = new int[n];

        // In du lieu trong mang
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }

        // Nhap du lieu thong Scanner
        Scanner sc = new Scanner(System.in);
        System.out.println("\nNhap vao gia tri cho mang a: ");
        for (int i = 0; i < a.length; i++) {
            System.out.print("a[" + i + "]: ");
            a[i] = sc.nextInt();
        }

        // In du lieu trong mang
        System.out.println("================");
        System.out.println("Mang a: ");
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }

        // Thay doi gia tri cua mang
        for (int i = 0; i < a.length; i++) {
            //a[i] = a[i]+1;
            //a[i]+=1;
            a[i]++;
        }

        // In du lieu trong mang
        System.out.println("================");
        System.out.println("Mang a: ");
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
    }
}
