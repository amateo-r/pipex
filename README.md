# pipex
A replication of shell pipe

## Notas
- Para fdp:
	- 0 es READ END.
	- 1 es WRITE END.

- Creo que la falla está en el uso de dup2. Debo hacer una revisión del concepto de los fd y dup2.
- No creo que haya que complicarse tanto y hacer una función para cada hijo. Creo que se puede factorizar.

