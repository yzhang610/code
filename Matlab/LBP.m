% LBP(�ֲ���ֵ������
% �㷨���裺
% 1����3*3��ģ���ͼ��ÿ�����ؽ��д����Ƚϵ�ǰ���غ���Χ���صĴ�С�������ڵ�ǰ���ص���1��С�ڵ���0��
% 2��������Χ�˸����ؽ��б��룬��˸�0��1���ÿ������һ��byte����Ȼ��һ���Ĺ����������޷�������
% 3�����������ֵ����ǰ���أ�
% 4���Դ�����ͼ��������򻮷֣�����ֳ�4*4��10*10��16*16�����򣬶�ÿ���������ֱ��ͼ���õ�16��100��256��ֱ��ͼ�����ֲ��̶�����
% 5����Щֱ��ͼ�������������Ը�����Ҫ����ʹ�á�

%��ȡһ��ͼƬ
img = imread('lena.jpg');
[m, n] = size(img);

imgn = zeros(m, n);
for i = 2:m-1
    for j = 2:n-1
        pow = 0;
        for p = i-1:i+1
            for q = j-1:j+1
                if img(p, q) > img(i, j)
                    if p ~= i || q ~= j       %3*3��˳ʱ��˳�����
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
hist = cell(1, 4);       %�����ĸ�����ֱ��ͼ��10*10̫��
hist{1} = imhist(img(1:floor(m/2), 1:floor(n/2)));
hist{2} = imhist(img(1:floor(m/2), floor(n/2)+1:n));
hist{3} = imhist(img(floor(m/2)+1:m, 1:floor(n/2)));
hist{4} = imhist(img(floor(m/2)+1:m, floor(n/2)+1:n));
for i = 1:4
    figure;
    plot(hist{i});
end



        
