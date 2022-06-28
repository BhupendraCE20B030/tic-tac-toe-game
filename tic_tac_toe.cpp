#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
int current_player;
void drawboard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-------------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-------------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "-------------\n";
}
bool placemarker(int slot)
{
    int row, col;
    row = slot / 3;
    if (slot % 3 == 0)
    {
        row = row - 1;
        col = 2;
    }
    else
    {
        col = (slot % 3) - 1;
    }
    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = current_marker;
        return true;
    }
    else
        return false;
}
int winner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;
    return 0;
}
void swap_player_marker()
{
    if (current_marker == 'X')
        current_marker = 'O';
    else
        current_marker = 'X';
    if (current_player == 1)
        current_player = 2;
    else
        current_player = 1;
}

void game()
{
    cout << "Player one please choose your marker : ";
    char marker_player1;
    cin >> marker_player1;
    current_player = 1;
    current_marker = marker_player1;
    int player_won;
    for (int i = 0; i < 9; i++)
    {
        cout << "\nIt's player " << current_player << "'s turn. Enter your slot : ";
    j:
        int slot;
        cin >> slot;
        if (slot < 1 || slot > 9)
        {
            cout << " The slot is invalid";
            goto j;
        }
        if (!placemarker(slot))
        {
            cout << "This slot is occupied";
            goto j;
        }
        cout << endl;
        drawboard();
        player_won = winner();
        if (player_won == 1)
        {
            cout << "\nPlayer one won!";
            break;
        }
        if (player_won == 2)
        {
            cout << "\nPlayer two won!";
            break;
        }
        swap_player_marker();
    }
    if (player_won == 0)
        cout << "\nIt's a Draw";
}

void game2()
{
    cout << "Please choose your marker : ";
    char marker_player1;
    cin >> marker_player1;
    current_player = 1;
    current_marker = marker_player1;
    int player_won;
    int slot;
    for (int i = 0; i < 4; i++)
    {
        cout << "\nIt's your turn. Enter your slot : ";
    j:
        cin >> slot;
        if (slot < 1 || slot > 9)
        {
            cout << " The slot is invalid";
            goto j;
        }
        if (!placemarker(slot))
        {
            cout << "This slot is occupied";
            goto j;
        }
        cout << endl;
        drawboard();
        player_won = winner();
        if (player_won == 1)
        {
            cout << "\nPlayer one won!";
            break;
        }
        if (player_won == 2)
        {
            cout << "\nPlayer two won!";
            break;
        }
        swap_player_marker();
        cout << "\nIt's computer's turn. \n";
    m:
        slot = (rand() % (10 - 1 + 1)) + 1;
        if (slot < 1 || slot > 9)
        {
            goto m;
        }
        if (!placemarker(slot))
        {
            goto m;
        }
        cout << endl;
        drawboard();
        player_won = winner();
        if (player_won == 1)
        {
            cout << "\nPlayer one won!";
            break;
        }
        if (player_won == 2)
        {
            cout << "\nPlayer two won!";
            break;
        }
        swap_player_marker();
    }
    e:
    cin >> slot;
    if (slot < 1 || slot > 9)
    {
        cout << " The slot is invalid";
        goto e;
    }
    if (!placemarker(slot))
    {
        cout << "This slot is occupied";
        goto e;
    }
    cout << endl;
    drawboard();
    player_won = winner();
    if (player_won == 1)
    {
        cout << "\nPlayer one won!";
    }
    if (player_won == 2)
    {
        cout << "\nPlayer two won!";
    }
    if (player_won == 0)
        cout << "\nIt's a Draw";
}
int main()
{
    cout << "Press 1 if you want to Play with friend : \n";
    cout << "Press 2 if you want to Play with computer : \n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        game();
        break;
    case 2:
        game2();
        break;
    default:
        cout << " Please select anyone of the given option!\n";
        break;
    }
    return 0;
}