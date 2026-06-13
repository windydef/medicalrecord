#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

  void input(void) {

    FILE * fptr;
    FILE * db;
    FILE * dpasien;
    FILE * dataid;
    char firstname[100], lastname[100], placeborn[100], dept[1000], symptoms[1000], treatment[1000], effectiveness[1000], u[1001], gender[2];
    char str [1001][1001], treat[1000][1000];
    int tgl, bln, thn, date, month, year, i, j, m, n, a, sym, dep, milih,trt, rujukan;
	n=0;
	m=0;
	
    printf("Patient ID (name_DOB.txt):\n");
    scanf("%s", u);

    fptr = fopen(u, "a+");
    db = fopen("database.txt", "a+");
    dpasien = fopen("datapenyakit.txt", "a+");
    dataid = fopen("dataid.txt", "a+");
    fprintf(dataid, "%s\n", u);

    printf("\n1. Date of checkup (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &date, &month, &year);
    fprintf(fptr, "Date of checkup    = %d/%d/%d\n", date, month, year);
    fprintf(db, "Date of checkup      = %d/%d/%d\n", date, month, year);
    fprintf(dpasien, "\nDOC%d%d%d  ", date, month, year);

    printf("\n2. First name                  : ");
    scanf("%s", firstname);
    fprintf(fptr, "Name          = %s \n", firstname);
    fprintf(db, "Name            = %s \n", firstname);
    
	printf("\n4. Last name                   : ");
    scanf("%s", lastname);
    fprintf(fptr, "Name          = %s \n", lastname);
    fprintf(db, "Name            = %s \n", lastname);
    
    printf("\n5. Gender (M/F)                : ");
    scanf("%s", &gender);
    fprintf(fptr, "Gender        = %s \n", gender);
    fprintf(db, "Gender          = %s \n", gender);

    printf("\n6. Place born                  : ");
    scanf("%s", &placeborn);
    fprintf(fptr, "Place born    = %s\n", placeborn);
    fprintf(db, "Place born      = %s\n", placeborn);

    printf("\n7. Date of birth (dd/mm/yyyy)  : ");
    scanf("%d/%d/%d", &tgl, &bln, &thn);
    fprintf(fptr, "Date of birth = %d/%d/%d\n", tgl, bln, thn);
    fprintf(db, "Date of birth = %d/%d/%d\n", tgl, bln, thn);

    printf("\n8. Visited departement         : 1. Neurology\t 2. General Illness\t 3. Eye center\t 4. Pulmology\n");
    printf("   Input department            : ");
    scanf("%d", &dep);
    
    if (dep == 1) {
      fprintf(fptr, "Department    = Neurology\n", dep);
      fprintf(db, "Department    = Neurology\n", dep);
      printf("   Symptoms neurology         :\n");
      
      FILE * fd;
      fd = fopen("neurosym.txt", "r");
      while (1) {
        if (fgets(str[n], 10000, fd)) n++;
        else break;
      }
      for (i = 0; i < n; i++) {
        printf("\t%s", str[i]);
      }
      fprintf(fptr, "Symptoms= \n");
      fprintf(db, "Symptoms= \n");
      symp1:
      printf("\nInput symptoms: ");
      scanf("%d", & sym);
      fprintf(fptr, "\t\t%s", str[sym - 1]);
      fprintf(db, "\t\t%s", str[sym - 1]);
      fputs(str[sym - 1], dpasien);
      printf("\nInput another symptoms?\n1. yes\n2. no\n");
      scanf("%d", &milih);     
      	if (milih == 1) 
      		{
      			goto symp1; 
      		}
      printf("\n9. Treatment: \n");
      FILE * aa;
      aa = fopen("neurotreat.txt", "r");
      fprintf(fptr, "Treatment= \n", dep);
      fprintf(db, "Treatment= \n", dep);
	      while (1) {
	        if (fgets(treat[m], 10000, aa)) m++;
	        else break;
	      }
	      for (j = 0; j < n; j++) {
	        printf("\t%s", treat[j]);
	      }
	      treat1:
	      printf("\n\tWhat kind of treatment: ");
	      scanf("%d", &trt);
	      fprintf(fptr, "\t\t%s", treat[trt - 1]);
	      fprintf(db, "\t\t%s", treat[trt - 1]);
	      fprintf(dpasien, "  %s  ", treat[trt - 1]);

	      printf("\nInput another treatment?\n1. Yes\n2. No\n");
	      scanf("%d", &milih);     
	      	if (milih == 1) 
	      		{
	      			goto treat1; 
	      		}
	goto effectiveness;
	return;
	  fclose(aa);  		
      fclose(fd);
    }
    if (dep == 2) {
      fprintf(fptr, "Department       = General Illness\n", dep);
      fprintf(db, "Department       = General Illness\n", dep);
      printf("     Symptoms general illness     :\n");
      FILE * b;
      b = fopen("generalsym.txt", "r");
      while (1) {
        if (fgets(str[n], 10000, b)) n++;
        else break;
      }
      for (i = 0; i < n; i++) {
        printf("\t%s", str[i]);
      }
      symp2:
      printf("\nInput symptoms: ");
      scanf("%d", &sym);
      fprintf(fptr, "\t\t%s", str[sym - 1]);
      fprintf(db, "\t\t%s", str[sym - 1]);
      fputs(str[sym - 1], dpasien);
      printf("Input another symptoms?\n1. yes\n2. no\n");
      scanf("%d", &milih);     
      	if (milih == 1) 
      		{
      			goto symp2; 
      		}
		       printf("\n9. Treatment: \n");
		      fprintf(fptr, "Treatment= \n", dep);
		      fprintf(db, "Treatment= \n", dep);
		      FILE * bb;
		      bb = fopen("generaltreat.txt", "r");
			      while (1) {
			        if (fgets(treat[m], 10000, bb)) m++;
			        else break;
			      }
			      for (j = 0; j < n; j++) {
			        printf("\t%s", treat[j]);
			      }
			      treat2:
			      printf("\nWhat kind of treatment (0 for reverse to another department: ");
			      scanf("%d", &trt);
			      	if(trt==0)
			      	{
			      		goto rujukan;
			      		return;
			      	}
			      fprintf(fptr, "\t\t%s", treat[trt-1]);
			      fprintf(db, "\t\t%s", treat[trt - 1]);
			      fputs(treat[trt - 1], dpasien);
			      printf("\nInput another treatment?\n1. Yes\n2. No\n");
			      scanf("%d", &milih);     
			      	if (milih == 1) 
			      		{
			      			goto treat2; 
			      		}
	goto effectiveness;
	return;
	  fclose(bb);  		
      fclose(b);
    }
    if (dep == 3) {
      fprintf(fptr, "Department       = Eye Center\n", dep);
      fprintf(db, "Department       = Eye Center\n", dep);
      printf("     Symptoms eyecenter         :\n");
      FILE * a;
      a = fopen("eyesym.txt", "r");
      while (1) {
        if (fgets(str[n], 10000, a)) n++;
        else break;
      }
      for (i = 0; i < n; i++) {
        printf("\t%s", str[i]);
      }
      symp3:
      printf("\nInput symptoms: ");
      scanf("%d", & sym);
      fprintf(fptr, "\t\t%s", str[sym - 1]);
      fprintf(db, "\t\t%s", str[sym - 1]);
      fputs(str[sym - 1], dpasien);
      printf("Input another symptoms?\n1. yes\n2. no\n");
      scanf("%d", &milih);     
      	if (milih == 1) 
      		{
      			goto symp3; 
      		}
		      printf("\n9. Treatment: \n");
		      fprintf(fptr, "Treatment= \n", dep);
		      fprintf(db, "Treatment= \n", dep);
		      FILE * cc;
		      cc = fopen("eyetreat.txt", "r");
			      while (cc) {
			        if (fgets(treat[m], 10000, cc)) m++;
			        else break;
			      }
			      for (j = 0; j < n; j++) {
			        printf("\t%s", treat[j]);
			      }
			      treat3:
			      printf("\n\tWhat kind of treatment: ");
			      scanf("%d", &trt);
			      fprintf(fptr, "\t\t%s", treat[trt - 1]);
			      fprintf(db, "\t\t%s", treat[trt- 1]);
			      fputs(treat[trt - 1], dpasien);
			      printf("\nInput another treatment?\n1. Yes\n2. No\n");
			      scanf("%d", &milih);     
			      	if (milih == 1) 
			      		{
			      			goto treat3; 
			      		}
	goto effectiveness;
	return;
	  fclose(cc);  		
      fclose(a);
      
    }
    if (dep == 4) {
      fprintf(fptr, "Department       = Pulmology\n", dep);
      fprintf(db, "Department       = Pulmology\n", dep);
      printf("     Symptoms pulmology        :\n");
      FILE * c;
      c = fopen("pulmosym.txt", "r");
      while (1) {
        if (fgets(str[n], 10000, c)) n++;
        else break;
      }
      for (i = 0; i < n; i++) {
        printf("\t%s", str[i]);
      }
      symp4:
      printf("\nInput symptoms: ");
      scanf("%d", & sym);
      fprintf(fptr, "\t\t%s", str[sym - 1]);
      fprintf(db, "\t\t%s", str[sym - 1]);
      fputs(str[sym - 1], dpasien);
      printf("Input another symptoms?\n1. yes\n2. no\n");
      scanf("%d", &milih);
	  printf("\n");      
      	if (milih == 1) 
      		{
      			goto symp4; 
      		}
	      printf("\n9. Treatment: \n");
	      fprintf(fptr, "Treatment= \n", dep);
	      fprintf(db, "Treatment= \n", dep);
	      FILE * dd;
	      dd = fopen("pulmotreat.txt", "r");
		      while (1) {
		        if (fgets(treat[m], 10000, dd)) m++;
		        else break;
		      }
		      for (j = 0; j < n; j++) {
		        printf("\t%s", treat[j]);
		      }
		      treat4:
		      printf("\n\tWhat kind of treatment: ");
		      scanf("%d", & sym);
		      fprintf(fptr, "\t\t%s", treat[sym - 1]);
		      fprintf(db, "\t\t%s", treat[sym - 1]);
		      fputs(treat[trt - 1], dpasien);
		      printf("\nInput another treatment?\n1. Yes\n2. No\n");
		      scanf("%d", &milih);     
		      	if (milih == 1) 
		      		{
		      			goto treat4; 
		      		}
	goto effectiveness;
	return;
	  fclose(c);
	  fclose(dd);  		
    }
		rujukan:
		printf("	Another departement         : 1. Neurology\t 2. Eye center\t 4. Pulmology\n\t");
	    	scanf("%d", &rujukan);
	    	if ( rujukan == 1) {
	    		fprintf(fptr, "Dept. Neurology\n");
	      		fprintf(db, "Dept. Neurology\n");
	      		fprintf(dpasien, "Dept. Neurology\n");
	    	}
	     	if ( rujukan == 2) {
	    		fprintf(fptr, "Dept. Eye Center\n");
	      		fprintf(db, "Dept. Eye Center\n");
	      		fprintf(dpasien, "Dept. Eye Center\n");
	    	}
	    	if ( rujukan == 2) {
	    		fprintf(fptr, "Dept. Pulmology\n");
	      		fprintf(db, "Dept. Pulmology\n");
	      		fprintf(dpasien, "Dept. Pulmology\n");
		}
 
	effectiveness:
    printf("\n8. Effectiveness               : ");
    scanf("%s", &effectiveness);
    fprintf(fptr, "Effectiveness   = %s\n\n", effectiveness);
    fprintf(db, "Effectiveness   = %s\n\n", effectiveness);
    fputs(effectiveness, dpasien);
    fclose(fptr);
    fclose(db);
    fclose(dpasien);
  }

void view(void) {
  int n, i, show, pilih, menu;
  n = 0;
  char u[1001], str[1001][1001], penyakit[1000], line[1000];
  FILE * fptr;
  FILE * datapasien;
  

  printf("\n\n********************************************Search for patient record**************************************************\n\n");
  printf("Input patient name & patient DOB with no space (e.x alibaba011096):\n");
  scanf("%s", u);
  printf("\n\n");
  fptr = fopen(u, "r");
  datapasien = fopen("datapenyakit.txt", "r");
  	if (fptr == NULL) {
      printf("%s's ID doesn't exist. DO you want to make this ID?\n1. Yes\n2. No\n", u);
      scanf("%d", &pilih );
	     if ( pilih == 1) {
	     	input();
	     }
		 if ( pilih == 2 ) {
		 	printf("=================================================== GOOD BYE===========================================================\n\n");
		 	return;
		 }
	  	return;
	  }
    printf("%s's ID already created. Do you want to show the medical record?\n", u);
    menupasien:
    printf("1. Search the previous symptoms\n2. Show all symptoms\n3. Search for another treatment\n4. Input another medical record\n");
    scanf("%d", &show);
    
    	switch(show) {
    			case 1:
    			{
    				fptr = fopen(u, "r");
    				printf("Input symptoms: ");
					scanf("%s", &penyakit);
						while (fgets(line,1000,fptr) != NULL)
						{
							if(strstr(line, penyakit))
								fputs (line, stdout);
						}
					fclose(fptr);
					printf("go back to menu? 1 for yes 0 for no\n");
					scanf("%d", &menu);
					printf("\n");
						if (menu == 1)
							{
								goto menupasien;
							}
						else {
							printf("               G O O D   B Y E                 \n");
							break;
    			}
    		}
    			case 2:
    				{
    					fptr = fopen(u, "r");
    				 while (1) {
					    if (fgets(str[n], 10000, fptr)) n++;
					    else break;
					 }
					    for (i = 0; i < n; i++) {
					    printf("%s", str[i]);
					    }
					 	printf("go back to menu? 1 for yes 0 for no\n");
						scanf("%d", &menu);
						printf("\n");
						if (menu == 1)
							{
								goto menupasien;
							}
						else {
						printf("               G O O D   B Y E                 \n"); 
						break;  
    				}
    			}
    			case 3:
    				{
    				printf("Input symptoms: ");
					scanf("%s", &penyakit);
						while (fgets(line,1000,datapasien) != NULL)
						{
							if(strstr(line, penyakit))
								fputs (line, stdout);
						}
					fclose(datapasien);
						printf("go back to menu? 1 for yes 0 for no\n");
						scanf("%d", &menu);
						printf("\n");
						if (menu == 1)
							{
								goto menupasien;
							}
						else {
							printf("               G O O D   B Y E                 \n");
							break;
						}
    				}
			case 4:
				{
				input();
				}
    	}
}

void searchid (void)
	{
		FILE * dataid;
		int id,m,j, show;
		char penyakit[100], line[1000], data[1000] [1000];
		printf("1. Patient id\n2. Show all id\n");
		scanf("%d", &id);
			if (id==1) {
				dataid = fopen("dataid.txt", "r"); //file rekap id
    				printf("ID keyword: ");
					scanf("%s", &penyakit);
						while (fgets(line,1000,dataid) != NULL)
						{
							if(strstr(line, penyakit))
								fputs (line, stdout);
								printf("\n");
						}
					fclose(dataid);
					printf("\nShow the medical record? 1 for yes 0 for no\n");
					scanf("%d", &show);
						if ( show == 1) {
							view();
							return; 
						}
			}
			if (id==2) {
	      			dataid = fopen("dataid.txt", "r");
		     		 while (1) {
		        	   if (fgets(data[m], 10000, dataid)) m++;
		        else break;
		      }
		      for (j = 0; j < m; j++) {
		        printf("\t%s", data[j]);
		      }
			}
	}

void main() { 

  int menu,m,j;
  char nama[100], menupilih, dtbase [1000] [1000];
  menu:
  system ("clear");
  printf("\n\n=============================================WELCOME TO BME's MEDICAL RECORD===========================================\n");
  printf("		Menu:																										      \n");
  printf("		   1. Input patient data																						  \n");
  printf("		   2. Patient record																							  \n");
  printf("		   3. See all patient medical record																			  \n");
printf("		   4. Search patient id record																			  \n");							
  printf("=======================================================================================================================\n");
  printf("choose menu: ");
  scanf("%d", & menu);
  switch (menu) {
  case 1:
    {
      input();
      break;
      	}
  case 2:
    {
      view();
      break;
    }
  case 3:
	{
	FILE * db;
	      db = fopen("database.txt", "r");
		      while (1) {
		        if (fgets(dtbase[m], 10000, db)) m++;
		        else break;
		      }
		      for (j = 0; j < m; j++) {
		        printf("\t%s", dtbase[j]);
		      }
	break;
	}
  case 4:
	{
	searchid();
	break;
	}
}
}
