  int ans = 0;
    for (int i = 0; i < M; i++) {
        if (UF.root(i) != i) continue;
        ans += UF.size(i)-1;
    }
    cout << ans << endl;