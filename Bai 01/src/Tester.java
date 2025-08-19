/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author tungi
 */
public class Tester {
    public static void main(String[] args) {
        Matrix m1 = new Matrix(5, 5);
        System.out.println("So luong dong: " + m1.getRows());
        System.out.println("So luong cot: " + m1.getCols());
        System.out.println("Gia tri cua mang la: ");
        m1.printAll();
    }
}
