
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

    public void printAll() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.format("%-5.2f", data[i][j]);
            }
            System.out.println("");
        }
    }

    public void inputValue() {
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

    public double getMaxValue() {
        // Lay ra duoc cai gia tri lon nhat cua matrix
        if (rows <= 0 || cols <= 0) {
            return Double.MIN_VALUE;
        }
        double max = data[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (max < data[i][j]) {
                    max = data[i][j];
                }
            }
        }
        return max;
    }

    public double getMinValue() {
        // Lay ra duoc cai gia tri lon nhat cua matrix
        if (rows <= 0 || cols <= 0) {
            return Double.MAX_VALUE;
        }
        double min = data[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (min > data[i][j]) {
                    min = data[i][j];
                }
            }
        }
        return min;
    }
    // Phương thức cộng hai ma trận

    public Matrix add(Matrix other) {
        // Kiểm tra điều kiện cộng ma trận (cùng kích thước)
        if (this.rows != other.rows || this.cols != other.cols) {
            System.out.println("Hai ma tran phai co cung kich thuoc de cong");
            return null;
        }

        Matrix result = new Matrix(this.rows, this.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = this.data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
}
