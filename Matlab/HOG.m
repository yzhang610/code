% 1、对原图像gamma校正，img = sqrt(img);
% 2、求图像竖直边缘，水平边缘，边缘强度，边缘斜率。
% 3、将图像每16*16（取其他也可以）像素分到一个cell中。对于256*256的lena来说，就分成了16*16个cell。
% 4、对每个cell求其梯度方向直方图。通常取9（取其他也可以）个方向（特征），也就是每360/9=40度分到一个方向，方向大小按像素边缘强度加权。最后归一化直方图。
% 5、每2*2（取其他也可以）个cell合成一个block，所以这里就是（16-1）*（16-1）=225个block。
% 6、所以每个block中都有2*2*9个特征，一个225个block，所以总的特征为225*36个。
% 当然一般HOG特征都不是对整幅图像取的，而是对图像中的一个滑动窗口取的。

%读取图像，并显示
img1 = imread('lena.jpg');
imshow(img1);
img = double(imread('lena.jpg'));
[m, n] = size(img);
%伽马校正
img = sqrt(img);
%求边缘
fy = [-1, 0, 1];     %定义竖直模板
fx = fy';            %定义水平模板
Iy = imfilter(img, fy, 'replicate');    %竖直边缘
Ix = imfilter(img, fx, 'replicate');    %水平模板
Ied = sqrt(Ix.^2 + Iy.^2);              %边缘强度
Iphase = Iy./Ix;                        %边缘斜率，有些为inf，-inf，nan，其中nan需要再处理一下
%求cell
step = 16;           %step*step个像素作为一个单元
orient = 9;          %方向直方图的方向个数
jiao = 360/orient;   %每个方向包含的角度数
Cell = cell(1, 1);   %所有的角度直方图，cell是可以动态增加的，所以先设了一个
ii = 1;
jj = 1;
%对每个cell求梯度直方图
for i = 1:step:m     %如果处理的m/step不是整数，最好是i=1:step:m-step
    ii = 1;
    for j = 1:step:n
        tempx = Ix(i:i + step - 1, j:j + step - 1);
        temped = Ied(i:i + step - 1, j:j + step - 1);
        temped = temped/sum(sum(temped));    %局部边缘强度归一化
        temphase = Iphase(i:i + step - 1, j:j + step - 1);
        Hist = zeros(1, orient);             %当前step*step像素块统计角度直方图，就是cell
        for p = 1:step
            for q = 1:step
                if isnan(temphase(p, q)) == 1%0/0会得到nan，如果像素是nan，重设为0
                    temphase(p, q) = 0;
                end
                ang = atan(temphase(p, q));  %atan求得是【-90 90】度之间
                ang = mod(ang*180/pi, 360);  %全部变正，-90到270
                if tempx(p, q) < 0           %根据x方向确定真正的角度
                    if ang < 90              %如果是第一象限
                        ang = ang + 180;     %移到第三象限
                    end
                    if ang > 270             %如果是第四象限
                        ang = ang - 180;     %移到第二象限
                    end
                end
                ang = ang + 0.0000001;       %防止ang为0
                Hist(ceil(ang/jiao)) = Hist(ceil(ang/jiao)) + temped(p, q);    %ceil向上取证，使用边缘强度加权
            end
        end
        Hist = Hist/sum(Hist);               %方向直方图归一化
        Cell{ii, jj} = Hist;                 %放入cell中
        ii = ii + 1;                         %针对Cell的y坐标循环变量
    end
    jj = jj + 1;                             %针对Cell的x坐标循环变量
end
%下面是求feature，2*2个cell合成一个block，没有显示的求block
[m, n] = size(Cell);
feature = cell(1, (m - 1)*(n - 1));
for i = 1:m - 1
    for j = 1:n - 1
        f = [];
        f = [f Cell{i, j}(:)' Cell{i, j + 1}(:)' Cell{i + 1, j}(:)',Cell{i + 1, j + 1}(:)'];
        feature{(i - 1) * (n - 1) + j} = f;
    end
end
%至此，feature即为所求
%下面显示
l = length(feature);
f = [];
for i = 1:l
    f = [f;feature{i}(:)'];
end
figure
mesh(f)
                

