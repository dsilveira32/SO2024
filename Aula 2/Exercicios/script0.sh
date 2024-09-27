#script1: if's is e um comentario
echo "Nome="
read nome
echo "Nome=$nome"
if [ "$nome" == "$1" ]; then
    echo "OK: $nome = $1"
else
    echo "NOK: $nome != $1"
fi
