
#include <iostream>
using namespace std;

void FirstFit(int noOFprocesses, int noOFblocks, int* ProcessSize, int* BlockSize)
{
    
    int* allocation = new int[noOFprocesses];

    for (int i = 0; i < noOFprocesses; i++)
    {
        allocation[i] = -1;
    }

    for (int x = 0; x < noOFprocesses; x++)
    {
        for (int y = 0; y < noOFblocks; y++)
        {
            if (BlockSize[y] >= ProcessSize[x])
            {
                allocation[x] = y;
                BlockSize[y] -= ProcessSize[x];
                break;
            }
        }
    }
    cout << "Process Size" << "  | " << "Block Number" << endl;
    for (int x = 0; x < noOFprocesses; x++)
    {
        cout << " " << ProcessSize[x] << "\t\t"<< " | " << "\t";
            if (allocation[x] != -1)
            {
                cout << allocation[x] + 1;
            }
            else
            {
                cout << "This process isn't allocated";
            }
        cout << endl;
    }
    
}

void BestFit(int noOFprocesses, int noOFblocks, int* ProcessSize, int* BlockSize)
{
    int* allocation = new int[noOFprocesses];

    for (int x = 0; x < noOFprocesses; x++)
    {
        allocation[x] = -1;
    }

    for (int x = 0; x < noOFprocesses; x++)
    {
        int BestIndex = -1;

        for (int y = 0; y < noOFblocks; y++)
        {
            if (BlockSize[y] >= ProcessSize[x])
            {
                if (BestIndex == -1) {
                    BestIndex = y;
                }
                else if (BlockSize[y] < BlockSize[BestIndex])
                {
                    BestIndex = y;
                }
            }

        }
        if (BestIndex != -1)
        {
            allocation[x] = BestIndex;
            BlockSize[BestIndex] -= ProcessSize[x];

        }

    }
    cout << "Process Number" << "  | " << "Block Number" << endl;
    for (int x = 0; x < noOFprocesses; x++)
    {
        cout << " " << ProcessSize[x] << "\t\t" << "|" << "\t";
        if (allocation[x] != -1)
        {
            cout << allocation[x] + 1;
        }
        else
        {
            cout << "This process isn't allocated";
        }
        cout << endl;
    }
}

void WorstFit(int noOFprocesses, int noOFblocks, int* ProcessSize, int* BlockSize)
{
    int* allocation = new int[noOFprocesses];

    for (int x = 0; x < noOFprocesses; x++)
    {
        allocation[x] = -1;
    }

    for (int x = 0; x < noOFprocesses; x++)
    {
        int WorstIndex = -1;

  
        for (int y = 0; y < noOFblocks; y++)
        {
            if (BlockSize[y] >= ProcessSize[x])
            {
                if (WorstIndex == -1)
                {
                    WorstIndex = y;
                }
                else if (BlockSize[y] > BlockSize[WorstIndex])
                {
                    WorstIndex = y;
                }
            }
        }
        if (WorstIndex != -1)
        {
            allocation[x] = WorstIndex;
            BlockSize[WorstIndex] -= ProcessSize[x];
        }
    }
    cout << "Process Number" << "  | " << "Block Number" << endl;
    for (int x = 0; x < noOFprocesses; x++)
    {
        cout << " " << ProcessSize[x] << "\t\t" << "|" << "\t";
        if (allocation[x] != -1)
        {
            cout << allocation[x] + 1;
        }
        else
        {
            cout << "This process isn't allocated";
        }
        cout << endl;
    }
}

int main()
{
    char again;

    do
    {
        int no_process;
        int no_block;
        int Method;
        cout << "Enter the number of processes:" << endl;
        cin >> no_process;
        int* processSize = new int[no_process];

        for (int x = 0; x < no_process; x++)
        {
            cout << "Enter the size of processes:" << endl;
            cin >> processSize[x];
        }


        cout << "Enter the number of blocks:" << endl;
        cin >> no_block;
        int* blocksize = new int[no_block];

        for (int x = 0; x < no_block; x++)
        {
            cout << "Enter the size of blocks:" << endl;
            cin >> blocksize[x];
        }
        cout << "Choose the of Memory Allocation Method you want:" << endl;
        cout << "1.Best Fit" << endl;
        cout << "2.First Fit" << endl;
        cout << "3.worst Fit" << endl;
        cout << "4.close" << endl;
        cin >> Method;
        if (Method == 1)
        {
            cout << "you choose Best fit" << endl;
            BestFit(no_process, no_block, processSize, blocksize);
        }
        else if (Method == 2)
        {
            cout << "you choose First fit" << endl;
            FirstFit(no_process, no_block, processSize, blocksize);
        }
        else if (Method == 3)
        {
            cout << "you choose Worst fit" << endl;
            WorstFit(no_process, no_block, processSize, blocksize);
        }
        else if (Method == 4)
        {
            exit(0);
        }
        cout << "If you want to try again please enter Y" << endl;
        cin >> again;
    } while (again == 'Y');
}