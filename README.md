# SIG-Burger

**Sistema de Gestão para Hamburgueria Delivery**

Um sistema desenvolvido em C para auxiliar na gestão de uma hamburgueria. Focado na simplicidade, integração e eficiência, o SIG-Burger oferece módulos para gerenciar clientes, pedidos, cardápio, estoque e financeiro, otimizando o fluxo de operações de um delivery moderno.

---

## Funcionalidades Principais

* **Gestão de Clientes**: Cadastro completo e histórico de pedidos.
* **Gestão de Pedidos**: Criação, atualização e acompanhamento de status.
* **Gestão de Cardápio**: Controle de lanches, bebidas e preços.
* **Controle de Estoque**: Monitoramento de ingredientes e insumos.
* **Gestão Financeira**: Cálculo de faturamento e controle de despesas.

---

## Como Executar

### Pré-requisitos

* Compilador C (GCC recomendado)
* Sistema operacional compatível (Windows/Linux/macOS)

### Compilação e Execução

```bash
# Clone o repositório
git clone [url-do-repositorio]

# Acesse o diretório
cd sig-burger

# Compile o programa
make

# Execute o sistema
./sig-burger

# Limpe os arquivos gerados na compilação (opcional)
make clean
```

---

## Interface do Sistema

O sistema apresenta uma interface em ASCII com navegação por menus:

```bash
        ╔══════════════════════════════════════════════════╗
        ║ SIG-BURGER - SISTEMA DE GESTÃO DE HAMBURGUERIA   ║
        ╠══════════════════════════════════════════════════╣
        ║                                                  ║
        ║ ► 1. Módulo Clientes                             ║
        ║ ► 2. Módulo Pedidos                              ║
        ║ ► 3. Módulo Cardápio                             ║
        ║ ► 4. Módulo Estoque                              ║
        ║ ► 5. Módulo Financeiro                           ║
        ║ ► 6. Sobre o SIG-BURGER                          ║
        ║ ► 0. Sair do Sistema                             ║
        ║                                                  ║
        ╚══════════════════════════════════════════════════╝
```

---

## Diagrama Modular — SIG-Burger

```bash
+-------------------+
|     CLIENTES      |
+-------------------+
         ↓
+-------------------+
|      PEDIDOS      |
+-------------------+
         ↓
+-------------------+
|     CARDÁPIO      |
+-------------------+
     ↙           ↘
+---------+   +------------+
| ESTOQUE |   | FINANCEIRO |
+---------+   +------------+
```

### Módulos

#### Clientes

Gerencia o cadastro e histórico de clientes.

#### Pedidos

Controla os pedidos e status de entrega.

#### Cardápio

Define os produtos, preços e composição dos lanches.

#### Estoque

Controla os ingredientes utilizados nos lanches.

* Cadastra e remove ingredientes.
* Atualiza quantidades disponíveis.
* Desconta automaticamente ingredientes quando um pedido é confirmado.
* Emite aviso quando o estoque está baixo.

#### Financeiro

Gerencia a movimentação financeira da hamburgueria.

* Registra valor total de cada pedido.
* Calcula faturamento diário/mensal.
* Registra despesas (compra de ingredientes, manutenção, etc.).
* Gera relatórios de lucro e prejuízo.

---

## Status do Desenvolvimento

| Módulo         | Status                | Descrição                     |
| -------------- | --------------------- | ----------------------------- |
| Menu Principal | 🚧 Em desenvolvimento | Interface de navegação        |
| Clientes       | 🚧 Em desenvolvimento | Cadastro e gestão de clientes |
| Pedidos        | 🚧 Em desenvolvimento | Criação e controle de pedidos |
| Cardápio       | 🚧 Em desenvolvimento | Controle de lanches e preços  |
| Estoque        | 🚧 Em desenvolvimento | Controle de insumos           |
| Financeiro     | 🚧 Em desenvolvimento | Controle de finanças          |

---

## Próximos Passos

* CRUD de todos mo modulos
* Implementar persistência em arquivos Binarios.
* Implementar relatórios e análises financeiras.
* Criar validação de entradas.

---

## Desenvolvedores

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/Felipe-edu34" target="_blank">
        <img src="https://github.com/Felipe-edu34.png" width="100px;" style="border-radius:50%;"/>
      </a><br />
      <sub><b>Felipe Eduardo</b></sub>
    </td>
    <td align="center">
      <a href="https://github.com/elxsson" target="_blank">
        <img src="https://github.com/elxsson.png" width="100px;" style="border-radius:50%;"/>
      </a><br />
      <sub><b>Elisson Tavares</b></sub>
    </td>
  </tr>
</table>
