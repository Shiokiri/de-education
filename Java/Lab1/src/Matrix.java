import java.util.Scanner;

public class Matrix {
    private int row, col;//行 列
    private int[][] data;
    Matrix(int row, int col)
    {
        this.row = row;
        this.col = col;
        this.data =  new int[this.row][this.col];
    }
    Matrix() {}
    public void setMatrix()
    {
        Scanner scanner = new Scanner(System.in);
        System.out.printf("请输入矩阵的行数，列数：\n");
        this.row = scanner.nextInt();
        this.col = scanner.nextInt();
        this.data =  new int[this.row][this.col];
        System.out.printf("矩阵为%d行%d列，请输入矩阵：\n", this.row, this.col);
        for(int i = 0; i < this.row; i++)
            for(int j = 0; j < this.col; j++) {
                this.data[i][j] = scanner.nextInt();
            }
    }
    public void printMatrix()
    {
        for(int i = 0; i < this.row; i++) {
            for(int j = 0; j < this.col; j++) {
                System.out.printf("%d ", this.data[i][j]);
            }
            System.out.printf("\n");
        }
    }
    public Matrix multiply(Matrix B)
    {
        Matrix A = this;
        Matrix C = new Matrix(A.row, B.col);
        if(A.col != B.row) {
            System.out.println("不可以相乘！");
            return C;
        }
        int n = A.col;
        for(int r = 0; r < C.row; r++) {
            for(int c = 0; c < C.col; c++) {
                for(int i = 0; i < n; i++)
                    C.data[r][c] += A.data[r][i] * B.data[i][c];
            }
        }
        return C;
    }
}
