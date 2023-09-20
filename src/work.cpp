    int n = nums.size(); 44
    int maxLength = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            bool isElegant = true;
            for (int k = i; k <= j; ++k) {
                for (int l = k + 1; l <= j; ++l) {
                    if ((nums[k] & nums[l]) != 0) {
                        isElegant = false;
                        break;
                    }
                }
                if (!isElegant) break;
            }
            if (isElegant) {
                maxLength = std::max(maxLength, j - i + 1);
            }
        }
    }
    
    return maxLength;
