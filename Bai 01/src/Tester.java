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
        Matrix m1 = new Matrix(2, 2);
        System.out.println("So luong dong: " + m1.getRows());
        System.out.println("So luong cot: " + m1.getCols());
        System.out.println("Gia tri cua mang la: ");
        m1.printAll();
        m1.inputValue();
        m1.printAll();
        System.out.println("Max: " + m1.getMaxValue());
        
        Matrix m2 = new Matrix(1, 2);
        m2.inputValue();
        Matrix m3 = new Matrix(2, 2);
        m3.inputValue();
        
        Matrix m4 = m1.add(m2);
        
        Matrix m5 = m1.add(m3);
        if(m5!=null)
        {
            System.out.println("m1+m3: ");
            m5.printAll();
        }
    }
}
