%�ο�����ĳ���
%ԭ����ַhttp://blog.sina.com.cn/s/blog_736aa0540101kzqb.html
clc;
clear;
close all;
%Haar-like�������μ���
board = 24;         %��ⴰ�ڿ��
num = 24;           %��ⴰ�ڻ�����
show = 1;           %1��Ϊ��ͼ
time = 0.001;       %��ͼ���
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if mod(board, num) ~= 0
    error('��ⴰ�ڿ�ȱ����Ƿֻ�����������')
else
    delta = board/num;      %��������ֵ
end
% %%%%%%%%%%         Haar����1������Һڣ���s, t) = (1, 2)        %%%%%%%%%%%%
% s = 1;
% t = 2;
% R = s:s:floor(num/s)*s;
% C = t:t:floor(num/t)*t;
% NUM = 0;          %haar��������
% for I = 1:length(R)
%     for J = 1:length(C)
%         r = R(I) * delta;      %Haar���ڸ�
%         c = C(J) * delta;      %Haar���ڿ�
%         nr = num - R(I) + 1;   %�з����ƶ�����
%         nc = num - C(J) + 1;   %�з����ƶ�����
%         Px0 = [0 r];          %���������ʼ��
%         Py0 = [0 c/2 c];
%         for i = 1:nr
%             for j = 1:nc
%                 Px = Px0 + (i - 1) * delta;     %����ȡ��
%                 Py = Py0 + (j - 1) * delta;      
%                 NUM = NUM + 1;
%                 if show
%                     plot([0 board], repmat((0:delta:board)', 1, 2)', 'k');
%                     hold on;
%                     plot(repmat((0:delta:board)', 1, 2), [0, board], 'k');
%                     axis tight;
%                     axis square;
%                     title('Haar���α�����ʾ');
%                     xlabel('x');
%                     ylabel('y');
%                     plot(Px, repmat(Py', 1,2), 'r', 'LineWidth', 5)
%                     plot(repmat(Px, 2, 1), repmat([Py(1) Py(end)]', 1, 2), 'r', 'LineWidth', 5);
%                     hold off;
%                     pause(time)
%                 end
%             end
%         end
%     end
% end
% NUM
% %%%%%%%%%%         Haar����2���ϰ��ºڣ���s, t) = (2, 1)        %%%%%%%%%%%%
% s = 2;
% t = 1;
% R = s:s:floor(num/s)*s;
% C = t:t:floor(num/t)*t;
% NUM = 0;          %haar��������
% for I = 1:length(R)
%     for J = 1:length(C)
%         r = R(I) * delta;      %Haar���ڸ�
%         c = C(J) * delta;      %Haar���ڿ�
%         nr = num - R(I) + 1;   %�з����ƶ�����
%         nc = num - C(J) + 1;   %�з����ƶ�����
%         Px0 = [0 r/2 r];          %���������ʼ��
%         Py0 = [0 c];
%         for i = 1:nr
%             for j = 1:nc
%                 Px = Px0 + (i - 1) * delta;     %����ȡ��
%                 Py = Py0 + (j - 1) * delta;      
%                 NUM = NUM + 1;
%                 if show
%                     plot([0 board], repmat((0:delta:board)', 1, 2)', 'k');
%                     hold on;
%                     plot(repmat((0:delta:board)', 1, 2), [0, board], 'k');
%                     axis tight;
%                     axis square;
%                     title('Haar���α�����ʾ');
%                     xlabel('x');
%                     ylabel('y');
%                     plot(repmat(Px, 2, 1), repmat(Py', 1, length(Px)), 'r', 'LineWidth', 3)
%                     plot(repmat([Px(1) Px(end)]', 1, 2), repmat(Py, 2, 1), 'r', 'LineWidth', 3);
%                     hold off;
%                     pause(time)
%                 end
%             end
%         end
%     end
% end
% NUM
%%%%%%%%%%       Haar����3�����Ұף��м�ڣ���s, t) = (1, 3)     %%%%%%%%%%%%
% s = 1;
% t = 3;
% R = s:s:floor(num/s)*s;
% C = t:t:floor(num/t)*t;
% NUM = 0;          %haar��������
% for I = 1:length(R)
%     for J = 1:length(C)
%         r = R(I) * delta;      %Haar���ڸ�
%         c = C(J) * delta;      %Haar���ڿ�
%         nr = num - R(I) + 1;   %�з����ƶ�����
%         nc = num - C(J) + 1;   %�з����ƶ�����
%         Px0 = [0 r];          %���������ʼ��
%         Py0 = [0 c/3 c*2/3 c];
%         for i = 1:nr
%             for j = 1:nc
%                 Px = Px0 + (i - 1) * delta;     %����ȡ��
%                 Py = Py0 + (j - 1) * delta;      
%                 NUM = NUM + 1;
%                 if show
%                     plot([0 board], repmat((0:delta:board)', 1, 2)', 'k');
%                     hold on;
%                     plot(repmat((0:delta:board)', 1, 2), [0, board], 'k');
%                     axis tight;
%                     axis square;
%                     title('Haar���α�����ʾ');
%                     xlabel('x');
%                     ylabel('y');
%                     plot(Px, repmat(Py', 1, 2), 'r', 'LineWidth', 5)
%                     plot(repmat(Px, 2, 1), repmat([Py(1) Py(end)]', 1, 2), 'r', 'LineWidth', 5);
%                     hold off;
%                     pause(time)
%                 end
%             end
%         end
%     end
% end
% NUM
% %%%%%%%%%% Haar����4�����Ұף��м�ڣ�2����ȣ�����s, t) = (1, 4) %%%%%%%%%%%%
% s = 1;
% t = 4;
% R = s:s:floor(num/s)*s;
% C = t:t:floor(num/t)*t;
% NUM = 0;          %haar��������
% for I = 1:length(R)
%     for J = 1:length(C)
%         r = R(I) * delta;      %Haar���ڸ�
%         c = C(J) * delta;      %Haar���ڿ�
%         nr = num - R(I) + 1;   %�з����ƶ�����
%         nc = num - C(J) + 1;   %�з����ƶ�����
%         Px0 = [0 r];          %���������ʼ��
%         Py0 = [0 c/4 c*3/4 c];
%         for i = 1:nr
%             for j = 1:nc
%                 Px = Px0 + (i - 1) * delta;     %����ȡ��
%                 Py = Py0 + (j - 1) * delta;      
%                 NUM = NUM + 1;
%                 if show
%                     plot([0 board], repmat((0:delta:board)', 1, 2)', 'k');
%                     hold on;
%                     plot(repmat((0:delta:board)', 1, 2), [0, board], 'k');
%                     axis tight;
%                     axis square;
%                     title('Haar���α�����ʾ');
%                     xlabel('x');
%                     ylabel('y');
%                     plot(Px, repmat(Py', 1, 2), 'r', 'LineWidth', 5)
%                     plot(repmat(Px, 2, 1), repmat([Py(1) Py(end)]', 1, 2), 'r', 'LineWidth', 5);
%                     hold off;
%                     pause(time)
%                 end
%             end
%         end
%     end
% end
% NUM
%%%%%%%%%%       Haar����5�����°ף��м�ڣ���s, t) = (3, 1)     %%%%%%%%%%%%
% s = 3;
% t = 1;
% R = s:s:floor(num/s)*s;
% C = t:t:floor(num/t)*t;
% NUM = 0;          %haar��������
% for I = 1:length(R)
%     for J = 1:length(C)
%         r = R(I) * delta;      %Haar���ڸ�
%         c = C(J) * delta;      %Haar���ڿ�
%         nr = num - R(I) + 1;   %�з����ƶ�����
%         nc = num - C(J) + 1;   %�з����ƶ�����
%         Px0 = [0 r/3 r*2/3 r];          %���������ʼ��
%         Py0 = [0 c];
%         for i = 1:nr
%             for j = 1:nc
%                 Px = Px0 + (i - 1) * delta;     %����ȡ��
%                 Py = Py0 + (j - 1) * delta;      
%                 NUM = NUM + 1;
%                 if show
%                     plot([0 board], repmat((0:delta:board)', 1, 2)', 'k');
%                     hold on;
%                     plot(repmat((0:delta:board)', 1, 2), [0, board], 'k');
%                     axis tight;
%                     axis square;
%                     title('Haar���α�����ʾ');
%                     xlabel('x');
%                     ylabel('y');
%                     plot(repmat(Px, 2, 1), repmat(Py', 1, length(Px)), 'r', 'LineWidth', 3)
%                     plot(repmat([Px(1), Px(end)]', 1, 2), repmat(Py, 2, 1), 'r', 'LineWidth', 3);
%                     hold off;
%                     pause(time)
%                 end
%             end
%         end
%     end
% end
% NUM
%%%%%%%%%%  Haar����6�����°ף��м��(2����ȣ�����s, t) = (4, 1��%%%%%%%%%%%%
% s = 4;
% t = 1;
% R = s:s:floor(num/s)*s;
% C = t:t:floor(num/t)*t;
% NUM = 0;          %haar��������
% for I = 1:length(R)
%     for J = 1:length(C)
%         r = R(I) * delta;      %Haar���ڸ�
%         c = C(J) * delta;      %Haar���ڿ�
%         nr = num - R(I) + 1;   %�з����ƶ�����
%         nc = num - C(J) + 1;   %�з����ƶ�����
%         Px0 = [0 r/4 r*3/4 r];          %���������ʼ��
%         Py0 = [0 c];
%         for i = 1:nr
%             for j = 1:nc
%                 Px = Px0 + (i - 1) * delta;     %����ȡ��
%                 Py = Py0 + (j - 1) * delta;      
%                 NUM = NUM + 1;
%                 if show
%                     plot([0 board], repmat((0:delta:board)', 1, 2)', 'k');
%                     hold on;
%                     plot(repmat((0:delta:board)', 1, 2), [0, board], 'k');
%                     axis tight;
%                     axis square;
%                     title('Haar���α�����ʾ');
%                     xlabel('x');
%                     ylabel('y');
%                     plot(repmat(Px, 2, 1), repmat(Py', 1, length(Px)), 'r', 'LineWidth', 3)
%                     plot(repmat([Px(1), Px(end)]', 1, 2), repmat(Py, 2, 1), 'r', 'LineWidth', 3);
%                     hold off;
%                     pause(time)
%                 end
%             end
%         end
%     end
% end
% NUM
%%%%%%%%%    Haar����7���������°ף������ڣ���s, t) = (2, 2��    %%%%%%%%%%%%
% s = 2;
% t = 2;
% R = s:s:floor(num/s)*s;
% C = t:t:floor(num/t)*t;
% NUM = 0;          %haar��������
% for I = 1:length(R)
%     for J = 1:length(C)
%         r = R(I) * delta;      %Haar���ڸ�
%         c = C(J) * delta;      %Haar���ڿ�
%         nr = num - R(I) + 1;   %�з����ƶ�����
%         nc = num - C(J) + 1;   %�з����ƶ�����
%         Px0 = [0 r/2 r];          %���������ʼ��
%         Py0 = [0 c/2 c];
%         for i = 1:nr
%             for j = 1:nc
%                 Px = Px0 + (i - 1) * delta;     %����ȡ��
%                 Py = Py0 + (j - 1) * delta;      
%                 NUM = NUM + 1;
%                 if show
%                     plot([0 board], repmat((0:delta:board)', 1, 2)', 'k');
%                     hold on;
%                     plot(repmat((0:delta:board)', 1, 2), [0, board], 'k');
%                     axis tight;
%                     axis square;
%                     title('Haar���α�����ʾ');
%                     xlabel('x');
%                     ylabel('y');
%                     plot(repmat(Px, 3, 1), repmat(Py', 1, length(Px)), 'r', 'LineWidth', 3)
%                     plot(repmat([Px(1), Px(end)]', 1, 3), repmat(Py, 2, 1), 'r', 'LineWidth', 3);
%                     hold off;
%                     pause(time)
%                 end
%             end
%         end
%     end
% end
% NUM
%%%%%%%%%      Haar����8�����ܰף��м�ڣ���s, t) = (3, 3��      %%%%%%%%%%%%
s = 3;
t = 3;
R = s:s:floor(num/s)*s;
C = t:t:floor(num/t)*t;
NUM = 0;          %haar��������
for I = 1:length(R)
    for J = 1:length(C)
        r = R(I) * delta;      %Haar���ڸ�
        c = C(J) * delta;      %Haar���ڿ�
        nr = num - R(I) + 1;   %�з����ƶ�����
        nc = num - C(J) + 1;   %�з����ƶ�����
        Px0 = [0 r/3 r*2/3 r];          %���������ʼ��
        Py0 = [0 c/3 c*2/3 c];
        for i = 1:nr
            for j = 1:nc
                Px = Px0 + (i - 1) * delta;     %����ȡ��
                Py = Py0 + (j - 1) * delta;      
                NUM = NUM + 1;
                if show
                    plot([0 board], repmat((0:delta:board)', 1, 2)', 'k');
                    hold on;
                    plot(repmat((0:delta:board)', 1, 2), [0, board], 'k');
                    axis tight;
                    axis square;
                    title('Haar���α�����ʾ');
                    xlabel('x');
                    ylabel('y');
                    plot(repmat(Px, 4, 1), repmat(Py', 1, length(Px)), 'r', 'LineWidth', 3)
                    plot(repmat([Px(1), Px(end)]', 1, 4), repmat(Py, 2, 1), 'r', 'LineWidth', 3);
                    hold off;
                    pause(time)
                end
            end
        end
    end
end
NUM

        
        
