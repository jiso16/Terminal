# Mini Terminal
리눅스 명령어를 사용할 수 있도록 C언어로 구현한 프로그램


## ls 명령어
1. ls를 입력하면 현재 경로에 존재하는 폴더명/파일명을 출력합니다.

2. 잘못 된 경로일 경우 아무것도 출력하지 않습니다.

3. 파일명의 경우 확장자로 구분합니다.

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




2.  cp [복사할 소스 파일의 경로] [복사되는 폴더의 경로와 저장할 파일명]을 입력하면 정상적인 경로인지 확인 후 입력한 경로에 파일이 복사됩니다.

    -복사하려는 소스파일이 다른 경로에 있을 경우


![cp2](https://user-images.githubusercontent.com/66424045/91552960-98a3db00-e967-11ea-814a-ac86c48ffc2c.PNG)


3. 어느 경우라도 경로가 잘 못 되었다면 아무 동작도 하지 않습니다.

## mkdir 명령어
1. mkidr[생성할 디렉토리명]을 입력하면 현재 경로에 비어있는 디렉토리가 생성됩니다.

2. 생성할 디렉토리랑 똑같으 디렉토리가 이미 존재한다면 아무 동작도 하지 않습니다.

![mkdir](https://user-images.githubusercontent.com/66424045/91553186-f33d3700-e967-11ea-9eb1-20f60fb86a7a.PNG)


## rmdir 명령어
1. rmdir[제거할 디렉토리명]을 입력하면 입력한 디렉토리가 삭제됩니다.

2. 빈 디렉토리만 지워집니다.

3. 제거할 디렉토리가 현재경로에 없다면 아무 동작도 하지 않습니다.

![rmdir](https://user-images.githubusercontent.com/66424045/91553402-4b743900-e968-11ea-8d13-a7e652acc905.PNG)


## rm 명령어

1. rm [제거할 디렉토리명]을 입력하면 입력한 디렉토리가 삭제됩니다.

2. 디렉토리 안에 파일이 존재한다면 파일들을 삭제한 후 디렉토리도 삭제합니다.
 
    -rmdir 명령어와의 차이점
 
3. 제거할 디렉토리가 현재경로에 없다면 아무 동작도 하지 않습니다.

![rm](https://user-images.githubusercontent.com/66424045/91553572-99893c80-e968-11ea-803e-d205d5ed2b98.PNG)

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTEzODIyNzkzNywtODc2NDA1MjAsLTExMD
IwMTcwNjYsNjA0MjQ2MTUsNjM1MDM1MjExLDE2MTc1ODg0NDIs
LTEzNzM2OTUxNDBdfQ==
-->