function [peak, sc, valley] = oct_feature(start, stop, F, alpha);
    N = length(F);
    F_filter = F(floor(N*start)+1:floor(N*stop));
    N_filter = length(F_filter);
    F_sort = sort(abs(F_filter),'descend');
    N_avg = floor(N_filter*alpha);
    peak = sum(F_sort(1:N_avg))/N_avg;
    valley = sum(F_sort(N_filter-N_avg+1:N_filter))/N_avg;
    sc = peak - valley;
end

