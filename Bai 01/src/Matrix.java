
import java.util.Scanner;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author tungi
 */
public class Matrix {

    private double[][] data;
    private int rows;
    private int cols;

    // Constructor
    public Matrix() {
        this.rows = 10;
        this.cols = 10;
        this.data = new double[rows][cols];
    }

    public Matrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        this.data = new double[rows][cols];
    }
    
    // Getter / Setter

    public double[][] getData() {
        return data;
    }

    public void setData(double[][] data) {
        this.data = data;
    }

    public int getRows() {
        return rows;
    }

    public void setRows(int rows) {
        this.rows = rows;
    }

    public int getCols() {
        return cols;
    }

    public void setCols(int cols) {
        this.cols = cols;
    }

    public void printAll(){
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.format("%-5.2f", data[i][j]);
            }
            System.out.println("");
        }
    }
    
    public void inputValue(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Nhap vao gia tri cua ma tran:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.format("data[%d][%d]: ", i, j);
                data[i][j] = sc.nextDouble();
            }
            System.out.println("");
        }
    }
    

}
