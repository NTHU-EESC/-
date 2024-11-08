NTHU EE Data Structures, 2018 spring 

功能：
1. 所有標準輸入(cin, scanf...等)被導向至檔案(in.txt)。請把測資檔案改名替換這個檔案。
2. 所有標準輸出(cout, printf...等)被導向至檔案(out.txt)
3. 自動比對輸出檔案(out.txt)與標準答案(golden.txt)，並顯示錯誤的位置。請把測資的標準答案改名成 golden.txt。
4. Windows CodeBlocks 及 Linux 環境可用 (電機入口工作站(140.114.24.31)沒有C++11，連到入口工作站須再連到有 C++11的內部工作站。例如打指令 ssh ws45.ee.nthu.edu.tw)
5. 可直接上傳 OJ (選C++或C++11)，上述額外功能自動會關閉。

備註：
1. 雖然程式包含導向檔案、自動比對的功能，但解題部份的程式仍維持用cin, cout, scanf, 或printf即可，不要(也不可)改利用檔案相關函式 (例如 fopen, freopen, fprintf, fscanf)。
2. 程式中的 PRINT() 是方便 debug 用的功能，可用可不用，並非一定要透過 PRINT 輸出文字。