// Função para toggle do dark mode
function toggleDarkMode() {
    const body = document.body;
    const isDarkMode = body.classList.toggle('dark-mode');
    
    // Salva a preferência no localStorage
    localStorage.setItem('darkMode', isDarkMode);
}

// Aplica o dark mode ao carregar a página
function applyDarkMode() {
    const isDarkMode = localStorage.getItem('darkMode') === 'true';
    if (isDarkMode) {
        document.body.classList.add('dark-mode');
    }
}

// Executa quando a página carrega
document.addEventListener('DOMContentLoaded', function() {
    applyDarkMode();
    
    // Adiciona evento ao botão (se existir)
    const darkToggle = document.querySelector('.dark-toggle');
    if (darkToggle) {
        darkToggle.addEventListener('click', toggleDarkMode);
    }
});