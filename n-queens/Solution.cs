
/*
  LeetCode: https://leetcode.com/problems/n-queens/discuss/1634663/C-Simple-Backtracking-Solution
*/

public class Solution
{
    public IList<IList<string>> SolveNQueens(int n)
    {
        var board = CreateEmptyBoard(n);

        var result = new List<IList<string>>();
        SolveNQueens(board, 0, result);
        return result;
    }

    private static void SolveNQueens(char[][] board,
                                              int col,
                                             List<IList<string>> result) {
        if (col >= board[0].Length)
        {
            AddBoardToResult(board, result);
            return;
        }
        
        for (var i = 0; i < board.Length; i++) {
            if (IsSafe(board, i, col)) {
                board[i][col] = 'Q';

                SolveNQueens(board, col + 1, result);

                board[i][col] = '.';
            }
        }
    }

    private static void AddBoardToResult(char[][] board,
                                       List<IList<string>> result) {
        var curBoard = new List<string>();
        for (var i = 0; i < board.Length; i++)
            curBoard.Add(string.Join("", board[i]));
        result.Add(curBoard);
    }
    
    private static char[][] CreateEmptyBoard(int n) {
        char[][] board = new char[n][];
        for (var i = 0; i < n; i++)
            board[i] = new char[n];
        for (var i = 0; i < board.Length; i++)
            for (var j = 0; j < board[0].Length; j++)
                board[i][j] = '.';
        return board;
    }
    
    private static bool IsSafe(char[][] board, int x, int y) {
        for (var i = 0; i < board.Length; i++)
            if (i != x && board[i][y] == 'Q')
                return false;
        for (var i = 0; i < board[0].Length; i++)
            if (i != y && board[x][i] == 'Q')
                return false;
        var curX = x - 1;
        var curY = y - 1;
        while (curX >= 0 &&
              curY >= 0)
            if (board[curX--][curY--] == 'Q')
                return false;
        curX = x + 1;
        curY = y + 1;
        while (curX < board.Length &&
              curY < board[0].Length)
            if (board[curX++][curY++] == 'Q')
                return false;
        curX = x - 1;
        curY = y + 1;
        while (curX >= 0 &&
              curY < board[0].Length)
            if (board[curX--][curY++] == 'Q')
                return false;
        curX = x + 1;
        curY = y - 1;
        while (curX < board.Length &&
              curY >= 0)
            if (board[curX++][curY--] == 'Q')
                return false;
        return true;
    }
}
