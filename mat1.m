%% Inicjalizacja

s=serial('/dev/ttyUSB1');
s.BaudRate = 115200;
fopen(s);
s
%% Gora dol

%"czyszczenie" drukarki
% while(s.BytesAvailable)
%     fscanf(s)
% end

% while(1)
%     %gora
%     fprintf(s,'x 600 y 600 z 600');  
%     disp('Gora')
%     while(s.BytesAvailable == 0)
%         ;
%     end
%     fscanf(s);
%     
%     %dol
%     fprintf(s,'x -600 y -600 z -600');
%     disp('Dol')
%     while(s.BytesAvailable == 0)
%         ;
%     end
%     fscanf(s);
% end
% 
% 
% 
% 
%% Sinus

while(s.BytesAvailable)
    fscanf(s)
end
poprzednie_a = 0;
poprzednie_b = round(promien*sin(0+(2/3*pi)));
poprzednie_c = round(promien*sin(0+(4/3*pi)));

promien = 500;
for t=0:0.1:6.28*20
    a=round(promien*sin(t));
    b=round(promien*sin(t+(2/3*pi)));
    c=round(promien*sin(t+(4/3*pi)));
    fprintf(s,'x %d y %d z %d\n',[a-poprzednie_a, b-poprzednie_b, c-poprzednie_c]);  
    while(s.BytesAvailable == 0)
        ;
    end
    fscanf(s);
   poprzednie_a = a;
   poprzednie_b = b;
   poprzednie_c = c;
end





