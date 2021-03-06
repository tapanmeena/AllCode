import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {

    private static final double CONFIDENCE = 1.96;

    private double meanVal = -1;
    private double stddevVal = -1;
    
    private final double[] results;

    // perform independent trials on an n-by-n grid
    public PercolationStats(int n, int trials)
    {
        if (n <= 0 || trials <= 0)
        {
            throw new IllegalArgumentException();
        }
        results = new double[trials];
        for (int i = 0; i < trials; i++)
        {
            Percolation percolation = new Percolation(n);
            while (!percolation.percolates()) {
                int row = StdRandom.uniform(n) + 1;
                int col = StdRandom.uniform(n) + 1;
                if (!percolation.isOpen(row, col)) {
                    percolation.open(row, col);
                }
            }
            results[i] = (double) percolation.numberOfOpenSites() / (n*n);
        }
    }
    // sample mean of percolation threshold 
    public double mean()
    {
        if (meanVal == -1)
        {
            return this.meanVal = StdStats.mean(results);
        }
        return this.meanVal;
    }

    // sample standard deviation of percolation threshold
    public double stddev()
    {
        if (stddevVal == -1)
        {
            this.stddevVal = StdStats.stddev(results);
        }
        return stddevVal;
    }

    // low endpoint of 95% confidence interval
    public double confidenceLo()
    {
        if (meanVal == -1)
        {
            mean();
        }
        if (stddevVal == -1)
        {
            stddev();
        }

        return meanVal - (CONFIDENCE * stddevVal / Math.sqrt(results.length));
    }
    // high endpoint of 95% confidence interval
    public double confidenceHi()
    {
        if (meanVal == -1)
        {
            mean();
        }
        if (stddevVal == -1)
        {
            stddev();
        }

        return meanVal + (CONFIDENCE * stddevVal / Math.sqrt(results.length));
    }

   // test client (see below)
    public static void main(String[] args)
    {
        int n = Integer.parseInt(args[0]);
        int trials = Integer.parseInt(args[1]);
        
        PercolationStats percolationStats = new PercolationStats(n, trials);
        System.out.println("mean = " + percolationStats.mean());
        System.out.println("stddev = " + percolationStats.stddev());
        System.out.println("95% confidence interval = [" + percolationStats.confidenceLo() + ", " + percolationStats.confidenceHi() + "]");
    }
}