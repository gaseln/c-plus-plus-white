void Reverse(std::vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n/2; ++i) {
        std::swap(v[i], v[n - 1 - i]);
    }
}

std::vector<int> Reversed(const std::vector<int>& v) {
    auto w  = v;
    Reverse(w);
    return w;
}
