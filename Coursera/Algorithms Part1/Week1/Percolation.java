import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {

    private final int n;
    private int openSites;

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
        this.openSites = 0;
        arr = new boolean[n*n + 2];

        uf = new WeightedQuickUnionUF(n*n + 2);
        uf2 = new WeightedQuickUnionUF(n*n + 1);
    }

    private int getArrIndex(int row, int col) {
        return (row-1)*this.n + col;
    }

    // opens the site (row, col) if it is not open already
    public void open(int row, int col)
    {
        //checking boundry counditions 
        if (row < 1 || col < 1 || row > this.n || col > this.n)
        {
            throw new IllegalArgumentException();
        }

        int index = (row-1) * this.n + col;

        if (!isOpen(row, col))
        {
            openSites++;
            this.arr[index] = true;
            if (row == 1)
            {
                uf.union(index, 0);
                uf2.union(index, 0);
            }

            if (row == this.n)
            {
                uf.union(index, this.n * this.n + 1);
            }

            if (row > 1 && isOpen(row-1, col))
            {
                uf.union(index, getArrIndex(row-1, col));
                uf2.union(index, getArrIndex(row-1, col));
            }

            if (row < n && isOpen(row+1, col))
            {
                uf.union(index, getArrIndex(row+1, col));
                uf2.union(index, getArrIndex(row+1, col));
            }
            
            if (col > 1 && isOpen(row, col-1)) 
            {
                uf.union(index, getArrIndex(row, col-1));
                uf2.union(index, getArrIndex(row, col-1));
            }
            
            if (col < n && isOpen(row, col+1))
            {
                uf.union(index, getArrIndex(row, col+1));
                uf2.union(index, getArrIndex(row, col+1));
            }
        }
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col)
    {
        if (row < 1 || col < 1 || row > this.n || col > this.n)
        {
            throw new IllegalArgumentException();
        }
        return this.arr[(row-1)*this.n + col];
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col)
    {
        if (row < 1 || col < 1 || row > this.n || col > this.n)
        {
            throw new IllegalArgumentException();
        }
        int index = (row-1)*this.n + col;

        return uf2.connected(0, index);
    }

    // returns the number of open sites
    public int numberOfOpenSites()
    {
        return this.openSites;
    }

    // does the system percolate?
    public boolean percolates()
    {
        return uf.connected(0, n*n+1);
    }
}