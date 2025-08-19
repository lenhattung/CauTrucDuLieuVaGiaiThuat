
public class Array_BaiTap2 {

    public static void main(String[] args) {
        // Khai bao mang hai chieu
        int[][] a = new int[10][5];

        // Duyet mang 2 chieu
        System.out.println("Mang a:");
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println("");
        }

        // Gan gia tri cho mang 2 chieu
        int value = 1;
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                a[i][j] = value;
                value++;
            }
        }

        // Duyet mang 2 chieu
        System.out.println("Mang a:");
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                //System.out.print(a[i][j] + " ");
                System.out.format("%-5d", a[i][j]);
            }
            System.out.println("");
        }
    }
}
