//
//  main.cpp
//  LeetCode
//
//  Created by ipuser on 2014/11/05.
//  Copyright (c) 2014年 qzhai. All rights reserved.
//

#include <iostream>
#include "TwoSum.h"
#include "MedianOfTwoSortedArrays.h"
#include "LongestSubstringWithoutRepeatingCharacters.h"
#include "AddTwoNumbers.h"
#include "LongestPalindromicSubstring.h"
#include "ZigZagConversion.h"
#include "ReverseInteger.h"
#include "StringtoInteger.h"
#include "PalindromeNumber.h"
#include "IntegertoRoman.h"
#include "RomantoInteger.h"
#include "LongestCommonPrefix.h"
#include "3Sum.h"
#include "3SumClosest.h"
#include "4Sum.h"
#include "LetterCombinationsOfPhoneNumber.h"
#include "RemoveNthNodeFromEndOfList.h"
#include "ValidParentheses.h"
#include "GenerateParentheses.h"
#include "SwapNodesInPairs.h"
#include "RemoveDuplicatesFromSortedArray.h"
#include "RemoveElement.h"
#include "ImplementstrStr.h"
#include "DivideTwoIntegers.h"
#include "ReverseNodesInKGroup.h"
#include "MergeKSortedLists.h"
#include "NextPermutation.h"
#include "LongestValidParentheses.h"
#include "SearchInRotatedSortedArray.h"
#include "SearchForARange.h"
#include "SearchInsertPosition.h"
#include "CountAndSay.h"
#include "CombinationSum.h"
#include "SingleNumber.h"
#include "MaximumDepthOfBinaryTree.h"
#include "ExcelSheetColumnNumber.h"
#include "CombinationSum.h"
#include "CombinationSumII.h"
#include "EquilibriumIndex.h"
#include "FirstMissingPositive.h"
#include "TrappingRainWater.h"
#include "MultiplyStrings.h"
#include "Permutations.h"
#include "PermutationsII.h"
#include "Anagrams.h"
#include "Pow(xn).h"
#include "N-Queens.h"
#include "N-QueensII.h"
#include "MaximumSubarray.h"
#include "SpiralMatrix.h"
#include "LengthOfLastWord.h"
#include "SpiralMatrixII.h"
#include "JumpGame.h"
#include "PermutationSequence.h"
#include "RotateList.h"
#include "UniquePaths.h"
#include "UniquePathsII.h"
#include "MergeIntervals.h"
#include "InsertInterval.h"
#include "PlusOne.h"
#include "AddBinary.h"
#include "Sqrt_X.h"
#include "SimplifyPath.h"
#include "SetMatrixZeroes.h"
#include "SearchA2DMatrix.h"
#include "SortColors.h"
#include "ClimbingStairs.h"
#include "Combinations.h"
#include "Subsets.h"
#include "RemoveDuplicatesFromSortedArrayII.h"
#include "SudokuSolver.h"
#include "SearchInRotatedSortedArrayII.h"
#include "RemoveDuplicatesFromSortedListII.h"
#include "TextJustification.h"
#include "PartitionList.h"
#include "MergeSortedArray.h"
#include "SubsetsII.h"
#include "LargestRectangleInHistogram.h"
#include "ScrambleString.h"
#include "GrayCode.h"
#include "MinimumWindowSubstring.h"
#include "DecodeWays.h"
#include "ReverseLinkedListII.h"
#include "RestoreIPAddresses.h"
#include "UniqueBinarySearchTrees.h"
#include "UniqueBinarySearchTreesII.h"
#include "InterleavingString.h"
#include "RecoverBinarySearchTree.h"
#include "SymmetricTree.h"
#include "BinaryTreeLevelOrderTraversal.h"
#include "BinaryTreeLevelOrderTraversalII.h"
#include "BinaryTreeZigzagLevelOrderTraversal.h"
#include "ConstructBinaryTreeFromPreorderAndInorderTraversal.h"
#include "ConstructBinaryTreeFromInorderAndPostorderTraversal.h"
#include "ConvertSortedListToBinarySearchTree.h"
#include "BalancedBinaryTree.h"
#include "PathSum.h"
#include "PathSumII.h"
#include "FlattenBinaryTreeToLinkedList.h"
#include "PopulatingNextRightPointersInEachNode.h"
#include "PopulatingNextRightPointersInEachNodeII.h"
#include "PascalsTriangle.h"
#include "PascalsTriangleII.h"
#include "Triangle.h"
#include "BestTimeToBuyAndSellStockII.h"
#include "BestTimeToBuyAndSellStockIII.h"
#include "WordLadder.h"
#include "BinaryTreeMaximumPathSum.h"
#include "PalindromePartitioning.h"
#include "PalindromePartitioningII.h"
//#include "SurroundedRegions.h"
#include "GasStation.h"
#include "CloneGraph.h"
#include "Candy.h"
#include "SingleNumberII.h"
#include "CopyListWithRandomPointer.h"
#include "WordBreak.h"
#include "WordBreakII.h"
#include "LinkedListCycle.h"
#include "LinkedListCycleII.h"
#include "BinaryTreePreorderTraversal.h"
#include "ReorderList.h"
#include "LRUCache.h"
#include "InsertionSortList.h"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    //LongestPalindromicSubstringTest test;
    //MedianTwoSortedArraysTest test;
    
    InsertionSortListTest test;
    test.test();
    return 0;
}

/*#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct CharAndFrequence
{
    char cha;
    int freq;
    CharAndFrequence(): cha(0), freq(0) {}
};
bool mycompare (CharAndFrequence i,CharAndFrequence j) { return (i.freq > j.freq); }
int main()
{
    
}
int main()
{
    string input = "baba";
//    cin >> input;
    vector<CharAndFrequence> res;
    for (int i = 0; i < 26; i ++) {
        CharAndFrequence temp;
        temp.cha = 'a' + i;
        temp.freq = 0;
        res.push_back(temp);
    }
    int length = input.size();
    for (int i = 0; i < length; i ++) {
        if ((input[i] - 'a') >=0 && (input[i] - 'a') < 26) {
            int index = input[i] - 'a';
            res[index].freq ++;
        }
        if ((input[i] - 'A') >=0 && (input[i] - 'A') < 26) {
            int index = input[i] - 'A';
            res[index].freq ++;
        }
    }
    std::sort(res.begin(), res.end(), mycompare);
    for (int i = 0; i < res.size(); i ++) {
        if(res[i].freq > 0)
            cout << res[i].cha << endl;
    }
    cout << endl;
    return 0;
}
*/
/*#include <iostream>
#include <string>
using namespace std;

double getPassCount(int id, int n, vector<int>& students, vector<string>& fm) {
    students[id] = 1;
    double total = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (fm[id][i] == 'Y' && students[i] == 0) {
            total += getPassCount(i, n, students, fm);
            count++;
        }
    }
    students[id] = 0;
    if (count > 0) {
        return 1 + total / count;
    }
    return 1;
}

int main() {
    int n = 2;
   // cin >> n;
    vector<string> friendMap;
    vector<int> students;
    for (int i = 0; i < n; i++) {
        string line = "YY";
        //cin >> line;
        friendMap.push_back(line);
        students.push_back(0);
    }
    cout << getPassCount(0, n, students, friendMap) ;
    return 0;
}
*/
