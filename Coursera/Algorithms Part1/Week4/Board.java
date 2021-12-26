import java.util.Arrays;
import edu.princeton.cs.algs4.Queue;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class Board {
    private final int size;
    private int[] board;

    // create a board from an n-by-n array of tiles,
    // where tiles[row][col] = tile at (row, col)
    public Board(int[][] tiles)
    {
        size = tiles[0].length();
        board = new int[size * size];
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                board[i * size + j] = tiles[i][j];
            }
        }
    }          

    private Board(int[] board)
    {
        size = (int) Math.sqrt(board.length);
        this.board = new int[board.length];
        for(int i = 0; i < board.length; i++)
            this.board[i] = board[i];
    }                             
    // string representation of this board
    public String toString()
    {
        StringBuilder s = new StringBuilder();
        s.append(size + "\n");
        for (int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                s.append(String.format("%2d ", board[i * size + j]));
            }
            s.append("\n");
        }
        return s.toString();
    }

    // board dimension n
    public int dimension()
    {
        return size;
    }

    // number of tiles out of place
    public int hamming()
    {
        int count = 0;
        for (int i = 0; i < size * size; i++)
            if (board[i] != i + 1 && board[i] != 0)
                count++;
        return count;
    }
    // sum of Manhattan distances between tiles and goal
    public int manhattan()
    {
        int sum = 0;
        for (int i = 0; i < size * size; i++)
            if (board[i] != i + 1 && board[i] != 0)
                sum += manhattan(board[i], i);
        return sum;
    }
    private int manhattan(int goal, int current) {
        int row, col;
        row = Math.abs((goal - 1) / size - current / size);
        col = Math.abs((goal - 1) % size - current % size);
        return row + col;
    }
    // is this board the goal board?
    public boolean isGoal()
    {
        for (int i = 0; i < size * size - 1; i++)
            if (board[i] != i + 1)
                return false;
        return true;
    }
    // does this board equal y?
    public boolean equals(Object y)
    {
        if (y == this) return true;
        if (y == null) return false;
        if (y.getClass() != this.getClass()) return false;

        Board that = (Board) y;
        return Arrays.equals(this.board, that.board);
    }
    // all neighboring boards
    public Iterable<Board> neighbors()
    {
        int index = 0;
        boolean found = false;
        Board neighbor;
        Queue<Board> q = new Queue<Board>();

        for (int i = 0; i < board.length; i++)
            if (board[i] == 0) {
                index = i;
                found = true;
                break;
            }

        if (!found) return null;

        // exchange with upper block
        if (index / size != 0) {
            neighbor = new Board(board);
            exch(neighbor, index, index - size);
            q.enqueue(neighbor);
        }

        // exchange with lower block
        if (index / size != (size - 1)) {
            neighbor = new Board(board);
            exch(neighbor, index, index + size);
            q.enqueue(neighbor);
        }

        // exchange with left block
        if ((index % size) != 0) {
            neighbor = new Board(board);
            exch(neighbor, index, index - 1);
            q.enqueue(neighbor);
        }

        // exchange with right block
        if ((index % size) != size - 1) {
            neighbor = new Board(board);
            exch(neighbor, index, index + 1);
            q.enqueue(neighbor);
        }

        return q;
    }
    // a board that is obtained by exchanging any pair of tiles
    public Board twin()
    {
        Board twin;
        if (size == 1) return null;
        twin = new Board(board);

        if (board[0] != 0 && board[1] != 0)
            exch(twin, 0, 1);
        else
            exch(twin, size, size + 1);
        return twin;
    }

    private Board exch(Board a, int i, int j) {
        int temp = a.board[i];
        a.board[i] = a.board[j];
        a.board[j] = temp;
        return a;
    }
    // unit testing (not graded)
    // public static void main(String[] args)
}