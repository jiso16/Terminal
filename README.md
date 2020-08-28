# Mini Terminal
리눅스 명령어를 사용할 수 있도록 C언어로 구현한 프로그램

## 명령어 정리

1. cd
 
   -cd [이동할 디렉토리명]을 입력하면 그 디렉토리로 이동합니다.
   
   -현재 경로에 없는 디렉토리명을 입력하면 아무 동작도 하지 않습니다.
  
2. ls 
 
   -현재 디렉토리의 파일명/폴더명을 화면에 나타내줍니다.
 
   -잘못 된 디렉토리라면 화면에 아무것도 띄우지 않습니다.
 
3. cp 
 
   -cp [복사할 소스파일명] [복사되는 폴더의 경로] 또는 cp [복사할 소스 파일의 경로] [복사되는 폴더의 경로] 를 입력하면 똑같은 파일이 복사됩니다.
 
   -잘못 된 파일 경로일 시 아무 동작도 하지 않습니다.
 
4. mkdir
 
    -mkdir [생성할 디렉토리명 ]을 입력하면 현재경로에서 빈 디렉토리가 생성됩니다.
  
    -이미 있는 디렉토리명과 겹치면 아무것도 생성하지 않습니다.
 
5. rmdir
  
    -rmdir [제거할 디렉토리명 ]을 입력하면 현재경로에서 디렉토리명을 확인하고 제거합니다.
  
    -현재경로에 없는 디렉토리명을 입력하면 아무동작도 하지 않습니다.
 
 6. rm
 
    -rm [제거할 디렉토리명]을 입력하면 현재경로에 존재하는 디렉토리인지 확인 후 디렉토리 안에 있는 파일까지 한번에 제거합니다.
    
    -현재 경로에 없는 디렉토리명을 입력하면 아무 동작도 하지 않습니다.
 
## ls 명령어
1. ls를 입력하면 현재 경로에 존재하는 폴더명/파일명을 출력합니다.

2. 잘못 된 경로일 경우 아무것도 출력하지 않습니다.

![ls](https://user-images.githubusercontent.com/66424045/91551976-fe8f6300-e965-11ea-9c6e-b54e0c2179da.PNG)

 ## cd 명령어

 1. cd [이동하려는 폴더명]을 입력하면 존재하는 폴더인지 확인 후 경로를 이동합니다.

      -[이동하려는 폴더명]이 현재 디렉토리에 존재하지 않으면 경로를 이동하지 않습니다.
   
![cd](https://user-images.githubusercontent.com/66424045/91552378-aa38b300-e966-11ea-8954-249b1aefc708.PNG)



2. cd .. 을 입력하면 현재 경로에서 한 단계 위의 상위 디렉토리로 경로를 이동합니다.
  
 
![uppercd](https://user-images.githubusercontent.com/66424045/91552495-df450580-e966-11ea-82e7-29fd55b040cf.PNG)




## cp 명령어

1. cp [복사할 소스파일명] [복사되는 폴더의 경로와 저장할 파일명]을 입력하면   정상적인 경로인지 확인 후 입력한 경로에 복사됩니다.

   -복사할 소스파일이 현재 경로에 존재할 경우
  
![cp1](https://user-images.githubusercontent.com/66424045/91552578-000d5b00-e967-11ea-9132-da07598db1d6.PNG)




3.  cp [복사할 소스 파일의 경로] [복사되는 폴더의 경로와 저장할 파일명]을 입력하면 정상적인 경로인지 확인 후 입력한 경로에 파일이 복사됩니다.


![다른경로의 파일 복사](https://user-images.githubusercontent.com/66424045/91271034-86ce0680-e7b4-11ea-97a6-6db47a54e968.PNG "다른경로의 파일 복사")

3. 어느 경우라도 경로가 잘 못 되었다면 아무 동작도 하지 않습니다.


<!--stackedit_data:
eyJoaXN0b3J5IjpbLTg3NjQwNTIwLC0xMTAyMDE3MDY2LDYwND
I0NjE1LDYzNTAzNTIxMSwxNjE3NTg4NDQyLC0xMzczNjk1MTQw
XX0=
-->