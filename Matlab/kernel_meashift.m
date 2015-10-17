close all
ri = round(randn(500, 1)*100 + 50);
nb_UniQueD = numel(unique(ri));
minScore = min(ri(:)) - 1;
maxScore = max(ri(:)) - 1;
scoreStd = std(ri);
sigma = 1.44 * scoreStd * nb_UniQueD^(-1/5);   %oversmoothed bandwidth
%sigma = 1.06 * scoreStd * numel(ri)^(-1/5);    %normal referebce bandwidth
numBins = min(256, 10 * nb_UniQueD/2);
Sp = linspace(minScore, maxScore, numBins + 1);
H = histc(ri, Sp);
Hraw = H / sum(H);
figure;
subplot(211);
bar(Hraw);
title('histogram estimation')
discrFactor = (maxScore - minScore) / numBins;
kerSize = round(5 * sigma / discrFactor);
if kerSize(1) < 3
    kerSize(1) = 3.0;
end
kerSize = double(kerSize);
K = fspecial('gaussian', [kerSize 1], double(sigma/discrFactor));
H = conv(Hraw, K, 'same');
H = H + 1e-10;
H = H ./ sum(H);
subplot(212)
bar(H);
title('after smooth')