% LBP(局部二值特征）
% 算法步骤：
% 1、用3*3的模板对图像每个像素进行处理，比较当前像素和周围像素的大小，将大于当前像素的置1，小于的置0；
% 2、对这周围八个像素进行编码，这八个0和1正好可以组成一个byte数，然后按一定的规则组成这个无符号数；
% 3、把这个数赋值给当前像素；
% 4、对处理后的图像进行区域划分，比如分成4*4、10*10或16*16的区域，对每个区域求得直方图，得到16、100或256个直方图（划分不固定）；
% 5、这些直方图就是特征，可以根据需要任意使用。

%读取一副图片
img = imread('lena.jpg');
[m, n] = size(img);

imgn = zeros(m, n);
for i = 2:m-1
    for j = 2:n-1
        pow = 0;
        for p = i-1:i+1
            for q = j-1:j+1
                if img(p, q) > img(i, j)
                    if p ~= i || q ~= j       %3*3的顺时针顺序编码
                        imgn(i, j) = imgn(i, j) + 2^pow;
                        pow = pow + 1;
                    end
                end
            end
        end
    end
end
figure;
imshow(imgn, []);
hist = cell(1, 4);       %划分四个区域直方图，10*10太多
hist{1} = imhist(img(1:floor(m/2), 1:floor(n/2)));
hist{2} = imhist(img(1:floor(m/2), floor(n/2)+1:n));
hist{3} = imhist(img(floor(m/2)+1:m, 1:floor(n/2)));
hist{4} = imhist(img(floor(m/2)+1:m, floor(n/2)+1:n));
for i = 1:4
    figure;
    plot(hist{i});
end



        
