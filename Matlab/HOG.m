% 1����ԭͼ��gammaУ����img = sqrt(img);
% 2����ͼ����ֱ��Ե��ˮƽ��Ե����Եǿ�ȣ���Եб�ʡ�
% 3����ͼ��ÿ16*16��ȡ����Ҳ���ԣ����طֵ�һ��cell�С�����256*256��lena��˵���ͷֳ���16*16��cell��
% 4����ÿ��cell�����ݶȷ���ֱ��ͼ��ͨ��ȡ9��ȡ����Ҳ���ԣ���������������Ҳ����ÿ360/9=40�ȷֵ�һ�����򣬷����С�����ر�Եǿ�ȼ�Ȩ������һ��ֱ��ͼ��
% 5��ÿ2*2��ȡ����Ҳ���ԣ���cell�ϳ�һ��block������������ǣ�16-1��*��16-1��=225��block��
% 6������ÿ��block�ж���2*2*9��������һ��225��block�������ܵ�����Ϊ225*36����
% ��Ȼһ��HOG���������Ƕ�����ͼ��ȡ�ģ����Ƕ�ͼ���е�һ����������ȡ�ġ�

%��ȡͼ�񣬲���ʾ
img1 = imread('lena.jpg');
imshow(img1);
img = double(imread('lena.jpg'));
[m, n] = size(img);
%٤��У��
img = sqrt(img);
%���Ե
fy = [-1, 0, 1];     %������ֱģ��
fx = fy';            %����ˮƽģ��
Iy = imfilter(img, fy, 'replicate');    %��ֱ��Ե
Ix = imfilter(img, fx, 'replicate');    %ˮƽģ��
Ied = sqrt(Ix.^2 + Iy.^2);              %��Եǿ��
Iphase = Iy./Ix;                        %��Եб�ʣ���ЩΪinf��-inf��nan������nan��Ҫ�ٴ���һ��
%��cell
step = 16;           %step*step��������Ϊһ����Ԫ
orient = 9;          %����ֱ��ͼ�ķ������
jiao = 360/orient;   %ÿ����������ĽǶ���
Cell = cell(1, 1);   %���еĽǶ�ֱ��ͼ��cell�ǿ��Զ�̬���ӵģ�����������һ��
ii = 1;
jj = 1;
%��ÿ��cell���ݶ�ֱ��ͼ
for i = 1:step:m     %��������m/step���������������i=1:step:m-step
    ii = 1;
    for j = 1:step:n
        tempx = Ix(i:i + step - 1, j:j + step - 1);
        temped = Ied(i:i + step - 1, j:j + step - 1);
        temped = temped/sum(sum(temped));    %�ֲ���Եǿ�ȹ�һ��
        temphase = Iphase(i:i + step - 1, j:j + step - 1);
        Hist = zeros(1, orient);             %��ǰstep*step���ؿ�ͳ�ƽǶ�ֱ��ͼ������cell
        for p = 1:step
            for q = 1:step
                if isnan(temphase(p, q)) == 1%0/0��õ�nan�����������nan������Ϊ0
                    temphase(p, q) = 0;
                end
                ang = atan(temphase(p, q));  %atan����ǡ�-90 90����֮��
                ang = mod(ang*180/pi, 360);  %ȫ��������-90��270
                if tempx(p, q) < 0           %����x����ȷ�������ĽǶ�
                    if ang < 90              %����ǵ�һ����
                        ang = ang + 180;     %�Ƶ���������
                    end
                    if ang > 270             %����ǵ�������
                        ang = ang - 180;     %�Ƶ��ڶ�����
                    end
                end
                ang = ang + 0.0000001;       %��ֹangΪ0
                Hist(ceil(ang/jiao)) = Hist(ceil(ang/jiao)) + temped(p, q);    %ceil����ȡ֤��ʹ�ñ�Եǿ�ȼ�Ȩ
            end
        end
        Hist = Hist/sum(Hist);               %����ֱ��ͼ��һ��
        Cell{ii, jj} = Hist;                 %����cell��
        ii = ii + 1;                         %���Cell��y����ѭ������
    end
    jj = jj + 1;                             %���Cell��x����ѭ������
end
%��������feature��2*2��cell�ϳ�һ��block��û����ʾ����block
[m, n] = size(Cell);
feature = cell(1, (m - 1)*(n - 1));
for i = 1:m - 1
    for j = 1:n - 1
        f = [];
        f = [f Cell{i, j}(:)' Cell{i, j + 1}(:)' Cell{i + 1, j}(:)',Cell{i + 1, j + 1}(:)'];
        feature{(i - 1) * (n - 1) + j} = f;
    end
end
%���ˣ�feature��Ϊ����
%������ʾ
l = length(feature);
f = [];
for i = 1:l
    f = [f;feature{i}(:)'];
end
figure
mesh(f)
                

