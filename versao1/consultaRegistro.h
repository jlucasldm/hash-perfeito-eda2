#include <stdio.h>
#include <stdlib.h>

int consultaRegistro(int pos, FILE* f){
	fseek(f, (pos) * sizeof(Registro), SEEK_SET);

	Registro r;
	fread(&r, sizeof(Registro), 1, f);
	if (r.ocupado == 0){
		fclose(f);
		return 0;
	}else if(r.ocupado == 1){
		fclose(f);
		return 1;
	}
}