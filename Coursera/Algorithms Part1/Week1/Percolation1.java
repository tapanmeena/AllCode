import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {

    // size of the grid
    private final int n;

    // number of open sites in the grid
    private int openSites;

    // array to store the grid
    private boolean[] arr;

    // Weighted Quick Union Find implementation
    private final WeightedQuickUnionUF uf;
    private final WeightedQuickUnionUF uf2;
    


    // creates n-by-n grid, with all sites initially blocked
    public Percolation(int n) 
    {
        if (n <= 0) 
        {
            throw new IllegalArgumentException();
        }

        this.n = n;
        openSites = 0;
        arr = new boolean[n*n + 2];
        uf = new WeightedQuickUnionUF(n*n + 2);
        uf2 = new WeightedQuickUnionUF(n*n + 1);
    }
    
    private boolean isSiteInvalid(int row, int col) {
        return row < 1 || col < 1 || row > this.n || col > this.n;
    }

    private int getArrIndex(int row, int col) {
        return (row-1)*this.n + col;
    }
    
    // open site (row, col) if it is not open already
    public void open(int row, int col) {
        if (isSiteInvalid(row, col)) {
            throw new IllegalArgumentException();
        }
        
        int index = getArrIndex(row, col);
        if (!isOpen(row, col)) {
            numOfOpenSites++;
            this.arr[index] = true;
            
            if (row == 1) {
                uf.union(index, 0);
                uf2.union(index, 0);
            }
            
            if (row == this.n)
                uf.union(index, this.n * this.n + 1);
            
            // top site
            if (row > 1 && isOpen(row-1, col)) {
                uf.union(index, getArrIndex(row-1, col));
                uf2.union(index, getArrIndex(row-1, col));
            }
            
            // bottom site
            if (row < n && isOpen(row+1, col)) {
                uf.union(index, getArrIndex(row+1, col));
                uf2.union(index, getArrIndex(row+1, col));
            }
            
            // left site
            if (col > 1 && isOpen(row, col-1)) {
                uf.union(index, getArrIndex(row, col-1));
                uf2.union(index, getArrIndex(row, col-1));
            }
            
            // right site
            if (col < n && isOpen(row, col+1)) {
                uf.union(index, getArrIndex(row, col+1));
                uf2.union(index, getArrIndex(row, col+1));
            }
        }
    }
    
    // is site (row, col) open?
    public boolean isOpen(int row, int col)  {
        if (isSiteInvalid(row, col)) {
            throw new IllegalArgumentException();
        }
        return this.arr[getArrIndex(row, col)];
    }
    
    // is site (row, col) full
    public boolean isFull(int row, int col)  {
        if (isSiteInvalid(row, col)) {
            throw new IllegalArgumentException();
        }
        
        int index = getArrIndex(row, col);
        
        return uf2.connected(0, index);
    }
    
    // number of open sites
    public int numberOfOpenSites()    {
        return numOfOpenSites;
    }
    
    // does the system percolate
    public boolean percolates()  {
        return uf.connected(0, n*n + 1);
    }
}