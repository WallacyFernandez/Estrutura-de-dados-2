const graph = {
    "Pedro": ["Maria", "João", "Luiz", "Camila", "Fernando", "Laura", "Rafaela", "Gustavo", "Larissa", "Carlos", "Miguel", "Mateus", "Lucas", "Jéssica", "Silvia", "Paulo", "José", "Mariana", "Sabrina"],
    "Maria": ["Pedro", "Camila", "Fernando", "João", "Luiz", "Vitor", "Bruna", "Gustavo", "Larissa", "Carlos", "Miguel", "Mateus", "Lucas", "Jéssica", "Silvia", "Paulo", "José", "Mariana", "Sabrina"],
    "João": ["Pedro", "Laura", "Fernando", "Camila", "Larissa", "Paulo", "Mariana", "Lucas", "Jéssica", "Rafaela"],
    "Ana": ["Camila", "Larissa", "Luana", "Lucas"],
    "Luiz": ["Pedro", "Carlos", "Lorena", "Jéssica", "Sabrina", "José", "Maria", "Camila"],
    "Camila": ["Maria", "Ana", "Gustavo", "Fernando", "Mariana", "Rafaela", "Luana"],
    "Fernando": ["Maria", "Larissa", "Jéssica", "Mateus", "Carlos", "Miguel", "Paulo", "Luana", "Sabrina", "Pedro"],
    "Laura": ["João", "Marcos", "Mateus", "Larissa", "Vitor"],
    "Carlos": ["Luiz", "Eduarda", "Pedro Henrique", "Maria", "Silvia", "José"],
    "Rafaela": ["Luiz", "Miguel", "Lorena", "Pedro", "Camila", "Luana"],
    "Gustavo": ["Camila", "Bruna", "Vitor", "Maria", "Pedro", "José"],
    "Larissa": ["Fernando", "Ricardo", "José", "Maria", "Jéssica", "Ana"],
    "Marcos": ["Laura", "José", "Maria", "Luiz", "Ricardo"],
    "Eduarda": ["Carlos", "Pedro Henrique", "Laura", "Lorena", "Lucas"],
    "Mateus": ["Rafaela", "Lorena", "Vitor", "Fernando", "Laura"],
    "Bruna": ["Gustavo", "Vitor", "Laura", "Silvia", "Carlos"],
    "Ricardo": ["Larissa", "José", "Marcos", "Fernando", "Carlos"],
    "Jéssica": ["Marcos", "Mariana", "Pedro", "Fernando", "Luiz"],
    "Pedro Henrique": ["Eduarda", "Miguel", "Lucas", "Luiz", "Sabrina"],
    "Lorena": ["Mateus", "Rafaela", "Eduarda", "Luiz"],
    "Lucas": ["Lorena", "Sabrina", "Miguel", "Eduarda", "Jéssica", "Vanessa", "Vitor"],
    "Sabrina": ["Lucas", "Ricardo", "Luana", "Miguel", "Vanessa", "Pedro", "Ana"],
    "José": ["Ricardo", "Marcos", "Carlos", "Luiz", "Fernando", "Larissa"],
    "Mariana": ["Jéssica", "Maria", "João", "Gustavo"],
    "Miguel": ["Pedro Henrique", "Vanessa", "Camila", "Lorena", "Sabrina", "Fernando"],
    "Vanessa": ["Miguel", "Luana", "Lucas", "Sabrina", "Mateus"],
    "Luana": ["Vanessa", "Miguel", "Lucas", "Ana", "Sabrina"],
    "Paulo": ["Luana", "Paulo", "Mateus", "Laura", "Carlos", "José"],
    "Silvia": ["Paulo", "Silvia", "Carlos", "Bruna", "Miguel"],
    "Vitor": ["Gustavo", "Bruna", "Mateus", "Vitor", "Maria"],
};

function searchConnections() {
    const searchInput = document.getElementById('search-input').value;
    const resultDiv = document.getElementById('result');

    if (graph[searchInput]) {
        resultDiv.innerHTML = '<h3>Amigos do ' + searchInput + '</h3><ul>' + graph[searchInput].map(friend => '<li>' + friend + '</li>').join('') + '</ul>';
    } else {
        resultDiv.innerHTML = '<p>O usuário ' + searchInput + ' não existe.</p>';
    }
}